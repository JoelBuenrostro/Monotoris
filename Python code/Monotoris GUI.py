
# Reference:

# tkinter:
# 

from tkinter import *
from tkinter import ttk
import serial

#arduinoPort = serial.Serial('COM4', 9600, timeout=5)
#arduinoData = arduinoPort.readline()
#tempdata = IntVar()
#tempdata.set(arduinoData)

#Windows
root = Tk()

#Widgets
mainframe = ttk.Frame(root, borderwidth=5, relief="sunken", width=200, height=100, padding=(3, 3, 12, 12))
portlabel = ttk.Label(mainframe, text="Port :")
baudlabel = ttk.Label(mainframe, text="Baudrate :")
templabel = ttk.Label(mainframe, text="Temperature :")
porttext = ttk.Label(mainframe, text="COM4")
baudtext = ttk.Label(mainframe, text="9600")
tempread = ttk.Label(mainframe, text="23") #textvariable=tempdata

#Layout
#Column 0
mainframe.grid(column=0, row=0, sticky=(N, S, E, W))
#Column 1
portlabel.grid(column=1, row=1, sticky=(N, W), padx=10, pady=5)
baudlabel.grid(column=1, row=2, sticky=(E, W), padx=10, pady=5)
templabel.grid(column=1, row=3, sticky=(N, S), padx=10, pady=5)
#Column 2
porttext.grid(column=2, row=1, sticky=(N), padx=10, pady=5)
baudtext.grid(column=2, row=2, sticky=(E, W), padx=10, pady=5)
tempread.grid(column=2, row=3, sticky=(N, S), padx=10, pady=5)

root.mainloop()