"""
Reference:

pyserial:
serial.Serial = The port is immediately opened on object creation, when a port is given.
readlines() = Read the entire row of data on port.

"""

import serial

arduinoPort = serial.Serial('COM6', 9600, timeout=0.1)
arduinoData = arduinoPort.read(size=5)