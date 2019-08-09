
# Reference:

# tkinter:
# 

import tkinter as tk

class window(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Monotoris")
        self.geometry("300x400")
        self.labelport = tk.Label(self, text="Port :", padx=5, pady=5)
        self.labelport.pack()

if __name__ == "__main":
    root = window()
    root.mainloop()