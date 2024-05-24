
import json

# patient's info

# name = input("Name: ")
# age = input("Age: ")
# address = input("Contact No: ")
# contact_no = input("Occupation: ")
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
    "name": "John",
    "age": 30,
    "married": True,
    "divorced": False,
    "children": ("Ann", "Billy"),
    "pets": None,
    "cars": [
        {"model": "BMW 230", "mpg": 27.5},
        {"model": "Ford Edge", "mpg": 24.1}
    ]
}

print(json.dumps(px))
print()
print(px)

try:
    output_filename = "print_px_not_json.txt"
    with open(output_filename, "w") as file:
        file.write(str(px))
except FileExistsError:
    with open("02_" + output_filename, "w") as file:
        file.write(str(px))

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
