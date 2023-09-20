
# import numpy

# speed = [99,86,87,88,111,86,103,87,94,78,77,85,86]

# x = numpy.mean(speed)

# print(x)

# x = numpy.median(speed)

# print(x)

# from scipy import stats

# import numpy
# from sklearn.metrics import r2_score
# numpy.random.seed(2)

# x = numpy.random.normal(3, 1, 100)
# y = numpy.random.normal(150, 40, 100) / x

# train_x = x[:80]
# train_y = y[:80]

# test_x = x[80:]
# test_y = y[80:]

# mymodel = numpy.poly1d(numpy.polyfit(train_x, train_y, 4))

# r2 = r2_score(train_y, mymodel(train_x))

# print(r2)
# import mysql.connector

# mydb = mysql.connector.connect(
#   host="localhost",
#   user="root",
#   password="29june2023",
# )
# mycursor = mydb.cursor()
# mycursor.execute("SHOW DATABASES")
# for x in mycursor:
#   print(x)

# import requests
# from bs4 import BeautifulSoup

# URL = "https://realpython.github.io/fake-jobs/"
# page = requests.get(URL)

# soap = BeautifulSoup(page.content, "html.parser")

# results = soap.find(id="ResultsContainer")
# # print(results.prettify())
# job_elements = results.find_all("div", class_ = "card-content")

# python_jobs = results.find_all(
#     "h2", string=lambda text: "python" in text.lower()
# )
# python_job_elements = [
#     h2_element.parent.parent.parent for h2_element in python_jobs
# ]
# for job_element in python_job_elements:
#     links = job_element.find_all("a")
#     link_url = links[1]["href"]
#     print(f"Apply here: {link_url}\n")
#     print("~~~~~~~~~~~")
# for job_element in python_jobs:
#     title_element = job_element.find("h2", class_="title")
#     company_element = job_element.find("h3", class_="company")
#     location_element = job_element.find("p", class_="location")
#     print(title_element.text.strip())
#     print(company_element.text.strip())
#     print(location_element.text.strip())
#     print()
# for job_element in job_elements:
#     title_element = job_element.find("h2", class_="title")
#     company_element = job_element.find("h3", class_="company")
#     location_element = job_element.find("p", class_="location")
#     print(title_element.text.strip())
#     print(company_element.text.strip())
#     print(location_element.text.strip())
#     print()
    # print(job_element, end="\n"*2)
# python_jobs = results.find_all("h2", string="Senior Python Developer")
# print(python_jobs)

# import pandas as pd
# import matplotlib.pyplot as plt
# csv_data = pd.read_csv("data.csv")
# # csv_data.loc[60, "Duration"] = 120

# csv_data['Duration'].plot(kind='hist')
# plt.show()


# import tkinter as tk

# def link_clicked(link):
#     print("Clicked link:", link)
#     # You can store this link in a variable, process it, etc.

# window = tk.Tk()

# def configure_link_button(widget, link):
#     widget.config(fg="blue", cursor="hand2", borderwidth=0, highlightthickness=0)
#     widget.bind("<Button-1>", lambda event: link_clicked(link))

# link_button = tk.Button(window, text="Click Me!")
# configure_link_button(link_button, "https://www.example.com")
# link_button.pack()

# window.mainloop()

# import pyperclip
# import time

# def capture_clipboard():
#     while True:
#         new_clipboard_content = pyperclip.paste()
#         if new_clipboard_content.startswith("http"):
#             print("Captured link:", new_clipboard_content)
#             # Do something with the link
#         time.sleep(1)

# capture_clipboard()
import tkinter as tk

root = tk.Tk()
root.geometry("300x300")

tk.Label(text="Label").pack()
tk.Button(text="Button").pack()
tk.Entry(text="Entry").pack()

root.mainloop()