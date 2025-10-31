#!/usr/bin/env python
# -*- coding: utf-8 -*-

#Libraries
import socket    #https://wiki.python.org/moin/UdpCommunication
import serial
import RPi.GPIO  as GPIO
import struct
import  time

ard=serial.Serial("/dev/ttyACM0", 115200)

ard.baudrate =115200
r = 0
y= 0
l=0
b =0
output=0
deadzone = 15/512
weakPoint = 80
maxSpeed = 255
speedScale = (1-deadzone)*(maxSpeed-weakPoint)


#Parameters
localPort=8888
bufferSize=1024

#Objects
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)  ## Internet,UDP

def calcMotorSpd(joy):

    a = int((abs((joy-512)/512)-deadzone)*speedScale+weakPoint)


    return max(min(a, 255),0)  

# function init 
def init():
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEPORT, 1)
    #sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1) #enable broadcasting mode
    sock.bind(('', localPort))
    print("UDP server : {}:{}".format(get_ip_address(),localPort))

# function main 
def main():
    while True:
        read_ser= ard.readline().strip()
        print(read_ser)

        try:
            r,y,l,b = [int(x) for x in read_ser.split(b" ")]
       
        
            msg = struct.pack('>BBBBBB', calcMotorSpd(r), calcMotorSpd(l), r<512, l<512, b, int((y/1024)*180))
        
            sock.sendto(msg, ('192.168.5.2', 8888))

        except Exception:
            continue

        # data, addr = sock.recvfrom(1024) # get data
        # print("received message: {} from {}\n".format(data,addr))
    
        # sock.sendto("RPi received OK",addr)  # write data
  


main()


# function get_ip_address 
def get_ip_address():
    """get host ip address"""
    ip_address = '';
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(("8.8.8.8",80))
    ip_address = s.getsockname()[0]
    s.close()
    return ip_address

