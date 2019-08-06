
# Reference:

# tkinter:
# 

import tkinter as tk
from tkinter import ttk
import serial

arduinoPort = serial.Serial('COM4', 9600, timeout=5)
arduinoData = arduinoPort.readline()

window = tk.Tk()
user_font = "Arial"
font_size = 16
window.title("Monotoris")
window.geometry("600x300")
window.minsize(width=300, height=150)

def update_label():
    int(arduinoData)
    label6.config(text=str(arduinoData))
    window.after(1000, update_label)



label1 = tk.Label(window, text="Port name : ", font=(user_font, font_size))
label2 = tk.Label(window, text=arduinoPort.name, font=(user_font, font_size))
label3 = tk.Label(window, text="Baudrate : ", font=(user_font, font_size))
label4 = tk.Label(window, text=arduinoPort.baudrate, font=(user_font, font_size))
label5 = tk.Label(window, text="Temperature : ", font=(user_font, font_size))
label6 = tk.Label(window, text=arduinoData, font=(user_font, font_size))

label1.grid(column=0, row=0)
label2.grid(column=1, row=0)
label3.grid(column=0, row=1)
label4.grid(column=1, row=1)
label5.grid(column=0, row=2)
label6.grid(column=2, row=2)

window.mainloop()