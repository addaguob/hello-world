# Backbone for client-server desktop application 

import customtkinter
import socket
import json
import pandas as pd

try:
    df = pd.read_csv("http://127.0.0.1:8000/lex.csv")
    print(df.to_string())
except (Exception):
    print("Can't connect and read.")
    

# importing socket module
# getting the hostname by socket.gethostname() method
hostname = socket.gethostname()

# getting the IP address using socket.gethostbyname() method
ip_address = socket.gethostbyname(hostname)

# printing the hostname and ip_address
print(f"Hostname: {hostname}")
print(f"IP Address: {ip_address}")

from datetime import datetime
from pytz import timezone

try:
    time_now = datetime.now(timezone('Asia/Manila'))
    print("Time in Asia/Manila is {}".format(time_now))
except Exception:
    print(Exception)
    
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


px = {
    "name": "Alex",
    "age": 45,
    "address": "Marikina Heights",
    "contact_no": "09162127281",
    "occupation": "Computer Engineer",
    "date": "2024-05-25",
    "frames": "ED9500",
    "lens": "Prog MC", 
    "total_amount": 2000,
    "deposit": 2000, 
    "balance": 0,
    "sales_staff": "Ate Bless",
    "doctor": "Dr. Kryzza"
}

print(json.dumps(px))

try:
    output_filename = "print_px_not_json.txt"
    with open(output_filename, "w") as file:
        json.dump(px, file, indent=4)
except FileExistsError:
    with open("02_" + output_filename, "w") as file:
        json.dump(px, file, indent=4)

frames = [
    "Contact Lens",
    "#Own F.",
    "#9100",
    "ED955",
    "ED990",
    "ED9150",
    "ED9150",
    "ED9500",
    "PE990",
    "PE9150",
    ]

lenses = [
    {"Ord" : "Ordinary"},
    {"SV" : "Single Vision lens"},
    {"MC" : "Multi-coated"},
    {"BB" : "Blue Blocker"},
    {"BTS" : "Blue blocker Transition"},
    {"KK" : "Kryptok"},
    {"TRG" : "Transition Gray"},
    {"Prog" : "Progressive lens"},
    {"Own F" : "Own Frame"},
    {"F. Only" : "Frame Only"}
]

# Employee account creation, world's compromised passwords top 10 accdg to security researchers
compromised_passw = {
    1: "12345",
    2: "admin",
    3: "12345678",
    4: "123456789",
    5: "1234",
    6: "12345",
    7: "password",
    8: "123",
    9: "Aa123456",
    10: "1234567890",
}
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
 