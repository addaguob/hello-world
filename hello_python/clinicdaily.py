
import socket
import json
import pandas as pd

df = pd.read_csv("http://127.0.0.1:8000/lex.csv")
print(df.to_string())

# importing socket module
# getting the hostname by socket.gethostname() method
hostname = socket.gethostname()
# getting the IP address using socket.gethostbyname() method
ip_address = socket.gethostbyname(hostname)
# printing the hostname and ip_address
print(f"Hostname: {hostname}")
print(f"IP Address: {ip_address}")
# patient's info
# name = input("Name: ")
# age = input("Age: ")
# address = input("Contact No: ")
# contact_no = input("Occupation: ")
# occupation = input("Occupation: ")
# date = input("Date: ")

# frames = input("Frames: ")
# lens = input("Lens: ")
# total_amount = input("Total Amount: ")
# deposit = input("Deposit Amount: ")
# balance = total_amount - deposit

# sales_staff = input("Sales Staff: ")
# doctor = input("Doctor: ")


# # sheet/page

# # header
# clinic_logo_path = ""
# date = ""
# doctor_in_charge = ""
# sales_personnel = []

# # table, row per patient (px)
# job_order = 0
# px_name = ""
# amount = 0
# deposit = 0
# balance = amount - deposit
# frame = ""
# lens = ""
# staff = ""

# # footer
# stocks = 0
# sold_items = 0
# added_items = 0
# checked_by = ""
# date_checked = ""


# px = {
#     "name": "John",
#     "age": 30,
#     "married": True,
#     "divorced": False,
#     "children": ("Ann", "Billy"),
#     "pets": None,
#     "cars": [
#         {"model": "BMW 230", "mpg": 27.5},
#         {"model": "Ford Edge", "mpg": 24.1}
#     ]
# }

# print(json.dumps(px))
# print()
# print(px)

# try:
#     output_filename = "print_px_not_json.txt"
#     with open(output_filename, "w") as file:
#         file.write(str(px))
# except FileExistsError:
#     with open("02_" + output_filename, "w") as file:
#         file.write(str(px))
frames = [
    "Contact Lens",
    "#Own F.",
    "#9100",
    "ED955",
    "ED990",
    "ED9150",
    "ED9150",
    "ED9500",
    "PE9150",
    "PE990",
    ]
# lenses = [
#     {"Ord" : "Ordinary"},
#     {"SV" : "Single Vision lens"},
#     {"MC" : "Multi-coated"},
#     {"BB" : "Blue Blocker"},
#     {"BTS" : "Blue blocker Transition"},
#     {"KK" : "Kryptok"},
#     {"TRG" : "Transition Gray"},
#     {"Prog" : "Progressive lens"},
#     {"Own F" : "Own Frame"},
#     {"F. Only" : "Frame Only"}
# ]

'''
Development Stages
1: Requirements Gathering
2: UI/UX Design
3: Backend and Frontend Development
4: QA and Testing
5: Launch
6: Iterate and Maintain


App Processes
1: Login
2: Sign up
3: Profile Creation
4: Update
5: Admin Panel / Dashboard


Simple App: UI and Storage (500-600 hours)
Medium App: UI, Databases, API 
    then: Real-time Messaging, 3rd party API, Social Media Integration, In-app purchasing (900-1000 hours)
Complex App: Streamming, Video chats, In-app Calls, Custom UI
(Unkown hours, consult dev team)

Important features:
UX = User Experience: make app do something well
UI = User Interface: make app look good doing that
UX copywriting: how to navigate the app
Platforms: native, cross-platform is good but native is better

hourly_rate x total_hours = total_cost

some give or take (+5-10% of total cost):
1: 3rd party integration
2: admin
3: infrastructure
3: maintenance costs
'''
 