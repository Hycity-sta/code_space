import tkinter as tk
from tkinter.colorchooser import *

root = tk.Tk()

def colorselect():
    color = askcolor()
    print(color)

tk.Button(root, text="颜色框", command=colorselect).pack(padx=10, pady=10)

root.mainloop()
