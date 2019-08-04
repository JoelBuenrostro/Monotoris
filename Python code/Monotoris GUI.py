
# Reference:

# pyserial:
# serial.Serial = The port is immediately opened on object creation, when a port is given.

import serial

arduinoPort = serial.Serial('COM6', 9600, timeout=1)
arduinoData = arduinoPort.readlines()

print (arduinoData)