import PySimpleGUI as sg

layout = [
    [sg.Text("Input File:"), sg.Input(key="infile"), sg.FileBrowse()],
    [sg.Text("Output Folder"), sg.Input(key="outfile"), sg.FolderBrowse()],
    [sg.Exit(), sg.Button("Convert to CSV")],
]

window = sg.Window("Excel-CSV Converter", layout)

while True:
    event, values = window.read()
    print(event, values)
    if event in (sg.WINDOW_CLOSED, "Exit"):
        break
    if event == "Convert to CSV":
        sg.popup_error("Oops!", title="Feature not yet implemented")
window.close()

