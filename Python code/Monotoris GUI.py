
# Reference:

# tkinter:
# 

import tkinter as tk
from tkinter import ttk
import serial

window = tk.Tk()
user_font = "Arial"
font_size = 16
arduinoPort = serial.Serial('COM4', 9600)

window.title("Monotoris")
window.geometry("600x600")
window.minsize(width=600, height=600)

label1 = tk.Label(window, text="Port name : ", font=(user_font, font_size))
label2 = tk.Label(window, text=arduinoPort.name, font=(user_font, font_size))
label3 = tk.Label(window, text="Baudrate : ", font=(user_font, font_size))
label4 = tk.Label(window, text=arduinoPort.baudrate, font=(user_font, font_size))

label1.grid(column=0, row=0)
label2.grid(column=1, row=0)
label3.grid(column=2, row=0)
label4.grid(column=3, row=0)

window.mainloop()