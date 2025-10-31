import serial
import RPi.GPIO  as GPIO
import time

ard=serial.Serial("/dev/ttyACM0", 115200)
ard.baudrate =115200
Rx = 0
y= 0
Lx=0
b=0
while True:
    read_ser=ard.readline().strip
    data = [int(x) for x in read_ser.split(" ")]
   # print(read_ser)

    tagFilter = read_ser[:2]
    valFilter = read_ser[2:]

    match tagFilter:
        case "1x":
            Rx = valFilter
        case "1y":
            y = valFilter
        case "2x":
            Lx = valFilter
        case "1b":
            b = valFilter
        
    print(Rx)
    print(Lx)
    print(y)
    print(b)








    
        

    
# import serial
# import time

#     # Configure the serial port (adjust '/dev/ttyACM0' and baud rate if needed)
# ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1)

# try:
#     while True:
#             if ser.in_waiting > 0:
#                 line = ser.readline().decode('utf-8').strip()
#                 print(f"Received from Arduino: {line}")
#                 time.sleep(0.1) # Small delay to prevent busy-waiting
# except KeyboardInterrupt:
#         print("Exiting...")
# finally:
#     ser.close()
 


