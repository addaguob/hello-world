import tkinter as tk
from tkinter.constants import *


root = tk.Tk()
photo = tk.PhotoImage(file="Lexda_icon.png")
root.iconphoto(False, photo)
frame = tk.Frame(root, relief=RIDGE, borderwidth=2)
frame.pack(fill=BOTH, expand=1)
label = tk.Label(frame, text="Hello, World")
label.pack(fill=X, expand=1)
button = tk.Button(frame, text="Exit", command=root.destroy)
button.pack(side=BOTTOM)
root.mainloop()