import tkinter as tk
from tkinter import ttk

root = tk.Tk()
root.title("Treeview Exercise")
root.geometry("500x500")

tview = ttk.Treeview(root)
tview["columns"] = ("Name", "ID", "Favorite Pizza")
tview.column("#0", width=120, minwidth=25)
tview.column("Name", anchor="w", width=120)
tview.column("ID",  anchor="center", width=80)
tview.column("Favorite Pizza",  anchor="w", width=120)

tview.heading("#0", text="Label", anchor="w")
tview.heading("Name", text="Name", anchor="w")
tview.heading("ID", text="ID", anchor="center")
tview.heading("Favorite Pizza", text="Favorite Pizza", anchor="w")

tview.insert(parent="", index="end", iid=0, text="Parent", values=("John", 1, "Peperoni"))
tview.pack(pady=20)

menu = tk.Menu(root)
root.config(menu=menu)

file_menu = tk.Menu(menu, tearoff=False)
edit_menu = tk.Menu(menu, tearoff=False)
view_menu = tk.Menu(menu, tearoff=False)
menu.add_cascade(label="File", menu=file_menu)
menu.add_cascade(label="Edit", menu=edit_menu)
menu.add_cascade(label="View", menu=view_menu)
file_menu.add_command(label="Open")

root.mainloop()
