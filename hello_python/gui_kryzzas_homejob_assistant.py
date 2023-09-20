
"""
A Simple Assistant for Kryzza's Home Job 
Sample input is a website:
https://www.yellow-pages.ph/business/feria-tantoco-daos-law-offices-3

This program will scrape information like below:
    'Store Name':"Feria Law",
    'Short Description':"Feria Tantoco Daos Law Offices",
    'Address':"8/F, DPC Place, 2322, Chino Roces Avenue Extension, Makati City 1200 Metro Manila",
    'Contact Number':"+63 (2) 8 889 8677",
    'Email Address':"contactus@ferialaw.com",
    'Website':"ferialaw.com"
    
A Simple Assistant for Kryzza's Home Job       
"""
import tkinter as tk
from tkinter import filedialog
import requests
from bs4 import BeautifulSoup
import threading
import pyperclip
import time
import pandas as pd

class LawFirmScraper:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("KRYZZA'S COPY-PASTE ASSISTANT")
        self.default_url = "https://www.yellow-pages.ph/business/feria-tantoco-daos-law-offices-3"
        self.captured_url = ""
        self.save_filepath = "kryzzas_law_firm_excel.xlsx"
        self.law_firm_info = {
            'Store Name':[],
            'Short Description':[],
            'Address':[],
            'Contact Number':[],
            'Email Address':[],
            'Website':[]
        }
        self.df_law_firms = pd.DataFrame(self.law_firm_info)
        # Imagine this GUI Window:
        #################################################################
        ##  button_scrape_wpage  ## entry_webpage_url                  ##
        #################################################################
        ##     label_store_name  ########################################
        ##     entry_store_name  ##   text_display_last_5_excel_rows   ##
        ##    label_description  ##   text_display_last_5_excel_rows   ##
        ##    entry_description  ##   text_display_last_5_excel_rows   ##
        ##        label_address  ##   text_display_last_5_excel_rows   ##
        ##        entry_address  ##   text_display_last_5_excel_rows   ##
        ##     label_contact_no  ##   text_display_last_5_excel_rows   ##
        ##     entry_contact_no  ##   text_display_last_5_excel_rows   ##
        ##  label_email_address  ##   text_display_last_5_excel_rows   ##
        ##  entry_email_address  ##   text_display_last_5_excel_rows   ##
        ##        label_website  ##   text_display_last_5_excel_rows   ##
        ##        entry_website  ##   text_display_last_5_excel_rows   ##
        #################################################################
        ## Open Exisitng ## entry_excel_filepath ## Save Law Firm Info ##
        #################################################################
        
        # Row 0  ----------------------------
        frame_0 = tk.Frame(master=self.window, relief=tk.FLAT, borderwidth=3)
        frame_0.pack()
        
        button_scrape = tk.Button(master=frame_0, text="Scrape Webpage:")
        button_scrape.pack(side=tk.LEFT)
        
        entry_webpage = tk.Entry(
            master=frame_0, width=50,
            text=self.default_url if self.captured_url=="" else self.captured_url
            )
        entry_webpage.pack(side=tk.LEFT)
        
        # Row 1  ------------------------------  
        frame_1 = tk.Frame(master=self.window, relief=tk.FLAT, borderwidth=3)
        frame_1.pack()  
        # Row 1, Col 0  ------------------------------  
        frame_1_0 = tk.Frame(master=frame_1, relief=tk.SUNKEN, borderwidth=3)
        frame_1_0.grid(row=1, column=0, sticky=tk.NS)
        
        for key in self.law_firm_info.keys():
            label_key = tk.Label(text=key, master=frame_1_0)
            label_key.pack(fill=tk.X)
            
            entry_value = tk.Entry(master=frame_1_0, width=40)
            entry_value.pack(fill=tk.X)
            entry_value.delete(0, tk.END)
            entry_value.insert(0, self.law_firm_info[key])
        # Row 1, Col 1  ------------------------------  
        frame_1_1 = tk.Frame(master=frame_1, relief=tk.SUNKEN, borderwidth=3)
        frame_1_1.grid(row=1, column=1, sticky=tk.NS)
        
        text_df = tk.Text(master=frame_1)
        text_df.grid(row=1, column=1, sticky=tk.NSEW)
        text_df.delete("1.0", tk.END)
        text_df.insert(tk.END, self.df_law_firms.to_string())
        
        # Row 2 ------------------------------------------ 
        frame_2 = tk.Frame(master=self.window, relief=tk.FLAT, borderwidth=3)
        frame_2.pack()

        button_savefile = tk.Button(master=frame_2, text="Save Law Firm Info", command=self.save_file)
        button_savefile.pack(side="right", padx=10, ipadx=10)
        
        self.entry_filepath = tk.Entry(master=frame_2, width=40)
        self.entry_filepath.pack(side="right", padx=10, ipadx=10)
        self.entry_filepath.delete(0, tk.END)
        self.entry_filepath.insert(0, self.save_filepath)

        button_openfile = tk.Button(master=frame_2, text="Open Excelfile:", command=self.select_excel_file)
        button_openfile.pack(side="right", padx=0, ipadx=10)
                
    def capture_clipboard(captured_url=""):
        while True:
            new_clipboard_content = pyperclip.paste()   # From pyperclip module
            if new_clipboard_content.startswith("http"):
                captured_url = new_clipboard_content
            time.sleep(2)  # From time module

    def start_clipboard_monitoring_thread(self):  # Call this function inside main()
        clipboard_thread = threading.Thread(target=capture_clipboard)  # From threading module
        clipboard_thread.daemon = True  # This makes the thread exit when the main program exits
        clipboard_thread.start()


    def scrape_webpage(self):
        default_url = "https://www.yellow-pages.ph/business/feria-tantoco-daos-law-offices-3"
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36"
            }
        webpage = requests.get(default_url, headers=headers)
        soup = BeautifulSoup(webpage.content, "html.parser")
        
        # law_firm_details = soup.find_all(
        #     "h1", string=lambda text: "python" in text.lower()
        # )

        # python_job_elements = [
        #     h2_element.parent.parent.parent for h2_element in python_jobs
        # ]
        # Scrape webpage with these infos
        self.law_firm_info['Store Name'] = lambda: soup.find("h1", class_="h1-tradename").text if soup.find("h1", class_="h1-tradename") else "None"
        self.law_firm_info['Short Description'] = lambda: soup.find("h2", class_="h2-businessname").text if soup.find("h2", class_="h2-businessname") else "None"
        self.law_firm_info['Address'] = lambda: soup.find("a", class_="biz-link yp-click").text if soup.find("a", class_="biz-link yp-click") else "None"
        self.law_firm_info['Contact Number'] = lambda: soup.find("span", class_="phn-txt").text if soup.find("span", class_="phn-txt") else "None"
        self.law_firm_info['Email Address'] = lambda: soup.find("a", class_="email-link").text if soup.find("a", class_="email-link") else "None"
        self.law_firm_info['Website'] = lambda: soup.find("a", class_="website").text if soup.find("a", class_="website") else "None"
          

    def select_excel_file(self):
        self.save_filepath = filedialog.askopenfilename(
            filetypes=[("Excel files", "*.xlsx"),
                       ("CSV files", "*.csv")]
            )
        if self.save_filepath:
            self.entry_filepath.delete(0, tk.END)
            self.entry_filepath.insert(0, self.save_filepath)
            self.df_law_firms = pd.read_excel(self.save_filepath) \
                if self.save_filepath.endswith == "xlsx" else \
                    pd.read_csv(self.save_filepath)
            
    def save_file(self):
        filename = self.entry_filepath.get()
        df_law_firm_info = pd.DataFrame(self.law_firm_info)
        if filename.endswith == "xlsx":
            df_law_firm_info.to_excel(filename, index=False)
        elif filename.endswith == "csv":
            df_law_firm_info.to_csv(filename, index=False)

    def run(self):
        self.window.mainloop()

if __name__ == "__main__":
    application = LawFirmScraper()
    application.run()