
# Reference:

# tkinter:
# 

from tkinter import *
from tkinter import ttk
import serial

#arduinoPort = serial.Serial(port="COM4", baudrate=9600, timeout=5)
#arduinoData = arduinoPort.readline()
#tempdata = IntVar()
#tempdata.set(arduinoData)


#Windows
root = Tk()

#Widgets
mainframe = ttk.Frame(root, borderwidth=5, relief="sunken", width=200, height=100, padding=(3, 3, 12, 12))
portlabel = ttk.Label(mainframe, text="Port :", font=("Arial", 16))
baudlabel = ttk.Label(mainframe, text="Baudrate :", font=("Arial", 16))
templabel = ttk.Label(mainframe, text="Temperature :", font=("Arial", 16))
portentry = ttk.Label(mainframe, text="COM4", font=("Arial", 16))
baudentry = ttk.Label(mainframe, text="9600", font=("Arial", 16))
tempread = ttk.Label(mainframe, text="23", font=("Arial", 16)) #textvariable=tempdata

#Layout
#Column 0
mainframe.grid(column=0, row=0, sticky=(N, S, E, W))
#Column 1
portlabel.grid(column=1, row=1, sticky=(N, W), padx=20, pady=5)
baudlabel.grid(column=1, row=2, sticky=(E, W), padx=20, pady=5)
templabel.grid(column=1, row=3, sticky=(N, S), padx=20, pady=5)
#Column 2
portentry.grid(column=2, row=1, sticky=(N), padx=20, pady=5)
baudentry.grid(column=2, row=2, sticky=(E, W), padx=20, pady=5)
tempread.grid(column=2, row=3, sticky=(N, S), padx=20, pady=5)

root.mainloop()