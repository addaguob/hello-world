import tkinter as tk
from tkinter.constants import *
from alexander_daguob import FavColors as color, Wait as wait


root = tk.Tk()
photo = tk.PhotoImage(file="Lexda_icon.png")
root.iconphoto(False, photo)
frame = tk.Frame(root, relief=RIDGE, borderwidth=2)
frame.pack(fill=BOTH, expand=1)

label = tk.Label(frame, text="Hello, World", bg=color.KHAKI)
label.pack(fill=X, expand=1)

label2 = tk.Label(frame, text="Alexander is here!", bg=color.HONEYDEW)
label2.pack(fill=X, expand=1)

root.mainloop()

wait.seconds(1)
button = tk.Button(frame, text="Exit", command=root.destroy)
button.pack(side=BOTTOM)

root.update()
