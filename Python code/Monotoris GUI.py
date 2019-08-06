
# Reference:

# tkinter:
# 

from tkinter import *
from tkinter import ttk
import serial

#arduinoPort = serial.Serial('COM4', 9600, timeout=5)
#arduinoData = arduinoPort.readline()

#Windows
root = Tk()

#Widgets
mainframe = ttk.Frame(root, borderwidth=5, relief="sunken", width=200, height=100, padding=(3, 3, 12, 12))
portlabel = ttk.Label(mainframe, text="Port :")
baudlabel = ttk.Label(mainframe, text="Baudrate :")
templabel = ttk.Label(mainframe, text="Temperature :")

#Layout
mainframe.grid(column=0, row=0, sticky=(N, S, E, W))
portlabel.grid(column=1, row=1, sticky=(N, W), padx=5, pady=5)
baudlabel.grid(column=1, row=2, sticky=(E, W), padx=5, pady=5)
templabel.grid(column=1, row=3, sticky=(N, S), padx=5, pady=5)

root.mainloop()