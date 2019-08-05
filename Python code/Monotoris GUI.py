
# Reference:

# tkinter:
# 

import tkinter as tk
from tkinter import ttk
import serial

window = tk.Tk()
arduinoPort = serial.Serial('COM4', 9600)

window.title("Monotoris")
window.geometry("600x600")
window.minsize(width=600, height=600)

label1 = tk.Label(window, text="Port name : ", font=("Arial", 16))
label2 = tk.Label(window, text=arduinoPort.name, font=("Arial", 16))

label1.grid(column=0, row=0)
label2.grid(column=1, row=0)

window.mainloop()