#!/bin/sh
sudo ifconfig wlan0 inet 192.168.5.1 up
sudo hostapd -d /etc/hostapd/hostapd.conf
