import serial

arduinoPort = serial.Serial('COM6', 9600)

print (arduinoPort.readline())