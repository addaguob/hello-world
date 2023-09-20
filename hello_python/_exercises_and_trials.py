import tkinter as tk
from tkinter import filedialog

# Create a function to toggle label state
def toggle_label_state(label):
    if label["relief"] == "raised":
        label.config(relief="sunken")
    else:
        label.config(relief="raised")

# Create a function to enable editing
def enable_editing():
    for i, label in enumerate(labels):
        label.pack_forget()
        text = tk.Text(root, height=1, width=50)
        text.insert("1.0", sentences[i])
        text.pack(fill=tk.BOTH)
        text_fields.append(text)

# Create a function to save changes
def save_changes():
    for i, text in enumerate(text_fields):
        sentences[i] = text.get("1.0", "end-1c")
        labels[i].config(text=sentences[i])
        text.pack_forget()
        labels[i].pack(fill=tk.BOTH)

# Create the main window
root = tk.Tk()
root.title("Customer Support")

# List of sentences
sentences = [
    "Opening the call",
    "Empathize/Apologize/Assure",
    "Confirm Account",
    "Probe/Ask Questions",
    "Solve Problem/Answer Question",
    "Offer Additional Assistance",
    "Close the Call"
]

# Create raised labels for each sentence
labels = []
text_fields = []
for sentence in sentences:
    label = tk.Label(root, text=sentence, relief="raised", padx=10, pady=10)
    label.pack(fill=tk.BOTH)
    label.bind("<Button-1>", lambda event, label=label: toggle_label_state(label))
    labels.append(label)

# Create a menu
menu = tk.Menu(root)
root.config(menu=menu)

# Create a File menu
file_menu = tk.Menu(menu)
menu.add_cascade(label="File", menu=file_menu, )
file_menu.add_command(label="Edit Contents", command=enable_editing)
file_menu.add_command(label="Save", command=save_changes)

root.mainloop()
