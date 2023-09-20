from alexander_daguob import Color, Wait
import tkinter as tk

class TempConverter:
    def __init__(self):
        # Set up the window
        self.window = tk.Tk()
        self.window.title("Temperature Converter")
        self.window.resizable(width=False, height=False)

        # Create the Fahrenheit entry frame with an Entry
        # widget and label in it
        self.frm_entry = tk.Frame(master=self.window)
        self.ent_temperature = tk.Entry(master=self.frm_entry, width=10)
        self.lbl_temp = tk.Label(master=self.frm_entry, text="\N{DEGREE FAHRENHEIT}")

        # Layout the temperature Entry and Label in frm_entry
        # using the .grid() geometry manager
        self.ent_temperature.grid(row=0, column=0, sticky="e")
        self.lbl_temp.grid(row=0, column=1, sticky="w")

        # Create the conversion Button and result display Label
        self.btn_convert = tk.Button(
            master=self.window,
            text="\N{RIGHTWARDS BLACK ARROW}",
            command=self.fahrenheit_to_celsius
        )
        self.lbl_result = tk.Label(master=self.window, text="\N{DEGREE CELSIUS}")

        # Set up the layout using the .grid() geometry manager
        self.frm_entry.grid(row=0, column=0, padx=10)
        self.btn_convert.grid(row=0, column=1, pady=10)
        self.lbl_result.grid(row=0, column=2, padx=10)
    
    def fahrenheit_to_celsius(self):
        """Convert the value for Fahrenheit to Celsius and insert the
        result into lbl_result.
        """
        self.fahrenheit = self.ent_temperature.get()
        self.celsius = (5 / 9) * (float(self.fahrenheit) - 32)
        self.lbl_result["text"] = f"{round(self.celsius, 2)} \N{DEGREE CELSIUS}"
        
    def runTC(self):
        # Run the application
        self.window.mainloop()
        
        
if __name__ == "__main__":
    tempconverter = TempConverter()
    tempconverter.runTC()