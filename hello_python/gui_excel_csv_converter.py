import tkinter as tk
from tkinter import filedialog
import pandas as pd

class ExcelCsvConverterApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Excel and CSV Converter")

        self.excel_filepath_button = tk.Button(root, text="Select Excel File", command=self.select_excel_file)
        self.excel_filepath_button.grid(row=0, column=0, padx=10, pady=10)
        
        self.excel_filepath_entry = tk.Entry(root)
        self.excel_filepath_entry.grid(row=0, column=1, padx=10, pady=10)
        
        self.convert_to_csv_button = tk.Button(root, text="Convert Excel to CSV", command=self.convert_to_csv)
        self.convert_to_csv_button.grid(row=0, column=2, padx=10, pady=10)
        
        self.csv_filename_entry = tk.Entry(root)
        self.csv_filename_entry.grid(row=0, column=3, padx=10, pady=10)
        
        self.csv_filepath_button = tk.Button(root, text="Select CSV File", command=self.select_csv_file)
        self.csv_filepath_button.grid(row=1, column=0, padx=10, pady=10)
        
        self.csv_filepath_entry = tk.Entry(root)
        self.csv_filepath_entry.grid(row=1, column=1, padx=10, pady=10)
        
        self.convert_to_excel_button = tk.Button(root, text="Convert CSV to Excel", command=self.convert_to_excel)
        self.convert_to_excel_button.grid(row=1, column=2, padx=10, pady=10)
        
        self.excel_filename_entry = tk.Entry(root)
        self.excel_filename_entry.grid(row=1, column=3, padx=10, pady=10)
        
        self.result_label = tk.Label(root, text="Recent command:")
        self.result_label.grid(row=2, column=0, padx=10, pady=10, sticky="e")
        
        self.result_entry = tk.Entry(root, width=50)
        self.result_entry.grid(row=2, column=1, columnspan=3, padx=10, pady=10, sticky="w")

        self.last_command = ""
        
    def select_excel_file(self):
        excel_file_path = filedialog.askopenfilename(filetypes=[("Excel files", "*.xlsx")])
        if excel_file_path:
            self.excel_filepath_entry.delete(0, tk.END)
            self.excel_filepath_entry.insert(0, excel_file_path)
        
    def select_csv_file(self):
        csv_file_path = filedialog.askopenfilename(filetypes=[("CSV files", "*.csv")])
        if csv_file_path:
            self.csv_filepath_entry.delete(0, tk.END)
            self.csv_filepath_entry.insert(0, csv_file_path)
        
    def convert_to_csv(self):
        excel_filepath = self.excel_filepath_entry.get()
        csv_filename = self.csv_filename_entry.get()
        
        if excel_filepath and csv_filename:
            df = pd.read_excel(excel_filepath)
            csv_filepath = f"{csv_filename}.csv"
            df.to_csv(csv_filepath, index=False)
            self.last_command = f"Excel to CSV successfully created: {csv_filepath}"
        else:
            self.last_command = "Please provide valid Excel filepath and CSV filename."
        
        self.result_entry.delete(0, tk.END)
        self.result_entry.insert(0, self.last_command)
        
    def convert_to_excel(self):
        csv_filepath = self.csv_filepath_entry.get()
        excel_filename = self.excel_filename_entry.get()
        
        if csv_filepath and excel_filename:
            df = pd.read_csv(csv_filepath)
            excel_filepath = f"{excel_filename}.xlsx"
            df.to_excel(excel_filepath, index=False)
            self.last_command = f"CSV to Excel successfully created: {excel_filepath}"
        else:
            self.last_command = "Please provide valid CSV filepath and Excel filename."
        
        self.result_entry.delete(0, tk.END)
        self.result_entry.insert(0, self.last_command)

if __name__ == "__main__":
    root = tk.Tk()
    app = ExcelCsvConverterApp(root)
    root.mainloop()
