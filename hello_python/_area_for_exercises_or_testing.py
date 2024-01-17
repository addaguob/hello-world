# # These are codes for little experiments
# import random
# import time

sent = "I am Alex"
for i in range(len(sent)):
    print(sent[i])

# def swing_trading_email(file_input, file_output):
#     with open(file_input, 'r') as trade_file:
#         trade_list = trade_file.readlines()
#     all_trades_list = []
#     trading_columns_dict = {  # Column-titles for first line in output
#         "Symbol": "Symbol",
#         "Trade Type": "Trade Type",
#         "Entry Price": "Entry Price",
#         "Stop Loss Price": "Stop Loss Price",
#         "Target Price": "Target Price"
#     }
#     all_trades_list.append(trading_columns_dict)
#     trade_count = 0  # First list would be the title for each column
#     with open(file_output, 'w') as trade_file:
#         column_title = ',\t'.join(each_value for each_value in all_trades_list[trade_count].values())
#         trade_file.write(f"{column_title}\n")
#     trade_has_started = False
#     line_count = 0  # just to skip first line (Title) from source file
#     for each_line in trade_list:
#         if each_line == '\n':
#             line_count = 1  # Reset. Just to detect a new line for every 3 lines.
#             if trade_has_started:
#                 all_trades_list.append(trading_columns_dict)
#                 trade_count += 1  # Serves as index counter for each update on all_trades_list
#                 with open(file_output, 'a') as trade_file:
#                     if len(trading_columns_dict["Symbol"]) < 3:
#                         new_trade_row = ',\t\t'.join(each_value for each_value in all_trades_list[trade_count].values())
#                     else:
#                         new_trade_row = ',\t'.join(each_value for each_value in all_trades_list[trade_count].values())
#                     trade_file.write(f"{new_trade_row}\n")
#         elif line_count > 0 and each_line != '\n':
#             trade_has_started = True
#             each_line = each_line.split()
#             word_count = 0
#             for each_word in each_line:
#                 each_word = each_word.split()
#                 if line_count == 1 and word_count == 0:
#                     trading_columns_dict["Symbol"] = each_line[word_count]
#                 elif line_count == 1 and word_count == 1:
#                     trading_columns_dict["Trade Type"] = each_line[word_count]
#                 elif line_count == 1 and word_count == 2:
#                     trading_columns_dict["Entry Price"] = each_line[word_count]
#                 elif line_count == 2 and word_count == 2:
#                     trading_columns_dict["Stop Loss Price"] = each_line[word_count]
#                 elif line_count == 3 and word_count == 1:
#                     trading_columns_dict["Target Price"] = each_line[word_count]
#                 word_count += 1
#             line_count += 1

#     # with open(file_output, 'a') as trade_file:
#     #     trade_file.write(f"{all_trades_list}\n\n")
#     #     for each_trade_dict in all_trades_list:
#     #         index = 0
#     #         for each_key, each_value in each_trade_dict.items():
#     #             print(f"{each_key}\t{each_value}")
#     #         print('----')
#     # for each_title in column_titles_list:
#     #     print(each_key[each_title])
#     # each_trade = '\t'.join(each_trade_dict[each_value] for each_value in each_trade_dict)
#     # trade_file.write(f"{each_trade}\n")


# def show_pyramid():
#     row = 7
#     space = row - 1
#     for i in range(1, row * 2, 2):
#         print(" " * space + "*" * i)
#         space -= 1


# class Robot:
#     def __init__(self, unit_no, name):
#         self.unit_no = unit_no
#         self.name = name

#     def move_head(self):
#         print("Moving head.")

#     def move_arms(self):
#         print("Moving arms.")

#     def move_feet(self):
#         print("Moving feet.")

#     def jump(self):
#         print("Jumping.")

#     def show_Robot_info(self):
#         print(f"Initiating {self.unit_no} {self.name}")


# class RobotSoldier(Robot):
#     def __init__(self, unit_no, name, weapon, rank):
#         super().__init__(unit_no, name)
#         self.soldier_weapon = weapon
#         self.soldier_rank = rank


# def is_status_successful():
#     print("Checking the status of the process...")
#     list_of_status = [True, True, True, False, False, False, False]
#     bool_to_return = random.choice(list_of_status)
#     return bool_to_return


# # fetch status for a given maximum number of tries with a given delay
# def retry_with_counter_until_status_is_successful(max_retry=10, sleep_time=3):
#     retry_count = 0
#     while True:
#         fetch_status = is_status_successful()
#         retry_count += 1
#         time.sleep(sleep_time)
#         if retry_count == max_retry:
#             raise Exception("Maximum retry reached. Request timed out.")
#         if fetch_status and retry_count < max_retry:
#             print(f"Status is successful: {fetch_status}\nNumber of tries: {retry_count}.")
#             break


# start_time = "7am"


# # fetch status for a given maximum time (seconds) with a given delay
# def retry2_with_counter_until_status_is_successful(max_seconds=10, sleep_time=2):
#     start_time = int(time.time())
#     time_out = int(time.time()) + max_seconds
#     while int(time.time()) <= time_out:
#         fetch_status = is_status_successful()
#         if fetch_status:
#             print(f"Status is successful: {fetch_status}\nTime consumed: {int(time.time()) - start_time}s.")
#             break
#         else:
#             time.sleep(sleep_time)
#     else:
#         raise Exception("Maximum retry reached. Request timed out.")


# class Complex:
#     def __init__(self, real_number, imaginary_number):
#         self.real_number = real_number
#         self.imaginary_number = imaginary_number

#     def add(self, complex_numbers):
#         real_number = self.real_number + complex_numbers.real_number
#         imaginary_number = self.imaginary_number + complex_numbers.imaginary_number
#         result = Complex(real_number, imaginary_number)
#         return result


# def generate_odd_numbers():
#     n = 1
#     while True:
#         if n % 2 == 1:
#             yield n
#         n += 1


# def change_start_time():
#     global start_time
#     start_time = "2pm"


# def timed_speaker(timespk = 'Default'):
#     minsec = '[(' + timespk[0:2] + ':' + timespk[2:4] + ')]'
#     person = timespk[4:]
#     return minsec + ' ' + person



# def main():
#     run_program = 'y'
#     while run_program.lower() != 'q':
#         # _________write program flow from here____________________________
#         list = [
#             'i am alex',
#             'she is kryzza',
#             'we are in love',
#         ]
#         list.insert(1, 'may mahal ako')
#         print(list)
        
#         si = 'ab'
#         si += 'c'
#         print(si)
#         # ---------end the program by pressing 'q'-------------------------
#         run_program = input("\nPress 'q' to EXIT PROGRAM or other keys to continue: ")


# main()

# import tkinter as tk

# def increase_value():
#     value = int(lbl_value["text"])
#     lbl_value['text'] = f"{value+1}"
#     value = int(ent_value['text'])
#     ent_value['text'] = f"{value+1}"
    
# def decrease_value():
#     value = int(lbl_value["text"])
#     lbl_value['text'] = f"{value-1}"
#     value = int(ent_value['text'])
#     ent_value['text'] = f"{value-1}"
    
# window = tk.Tk()
# window.title("Sample Window")
# window.rowconfigure(0, minsize=50, weight=1)
# window.columnconfigure([0,1,2], minsize=50, weight=1)

# btn_decrease = tk.Button(master=window, text='-', command=decrease_value)
# btn_decrease.grid(row=0, column=0, sticky="nwse")

# lbl_value = tk.Label(master=window, text='0')
# lbl_value.grid(row=0, column=1, sticky="nwse")
# ent_value = tk.Label(master=window, text='10', relief="sunken", bg="white")
# ent_value.grid(row=1, column=1, sticky="nwse")

# btn_increase = tk.Button(master=window, text='+', command=increase_value)
# btn_increase.grid(row=0, column=2, sticky="nwse")

# window.mainloop()

# law_firm_info = {
#             'Store Name':["Alex Law"],
#             'Short Description':["A law firm for everyone."],
#             'Address':["10 Mahogany, Dao. St., Marikina City"],
#             'Contact Number':["+639162127281"],
#             'Email Address':["alexfirm@gmail.com"],
#             'Website':["alexfirm.com"],
# }

# df = pd.DataFrame(law_firm_info)
# print(df)
# df.to_excel("sample_excel01.xlsx", index=False)
# df.to_excel("sample_excel02.xlsx")

# import pandas as pd

# # Sample data
# data = {'Name': ['Alice', 'Bob', 'Charlie'],
#         'Age': [25, 30, 22]}

# # Create a DataFrame
# df = pd.DataFrame(data)

# # Create a new row as a dictionary
# new_row = {'Name': 'David', 'Age': 28}

# # Add the new row using loc
# df = df._append(new_row, ignore_index=True)

# print(df)

# import tkinter as tk

# root = tk.Tk()

# # Create two labels with different padx and ipadx values
# label1 = tk.Label(root, text="Label with padx and ipadx")
# label1.pack(padx=10, ipadx=5)

# label2 = tk.Label(root, text="Label with padx and ipadx")
# label2.pack(padx=5, ipadx=5)

# root.mainloop()

# import tkinter as tk

# def scroll_text_x(*args):
#     text.xview(*args)

# def scroll_text_y(*args):
#     text.yview(*args)

# root = tk.Tk()
# root.title("Scrollable Text Example")

# # Create a Text widget
# text = tk.Text(root, wrap=tk.NONE)
# text.pack(fill=tk.BOTH, expand=True)

# # Create horizontal scrollbar
# scrollbar_x = tk.Scrollbar(root, orient=tk.HORIZONTAL, command=scroll_text_x)
# scrollbar_x.pack(fill=tk.X)

# # Create vertical scrollbar
# scrollbar_y = tk.Scrollbar(root, orient=tk.VERTICAL, command=scroll_text_y)
# scrollbar_y.pack(fill=tk.Y)

# # Configure Text widget to use the scrollbars
# text.config(xscrollcommand=scrollbar_x.set, yscrollcommand=scrollbar_y.set)

# # Insert some content into the Text widget
# for i in range(100):
#     text.insert(tk.END, f"Line {i}\n")

# root.mainloop()

# for num in range(5):
#     print(num, end=" ")
# print("\n" + str(num)) # check if num still exists ouside the for-loop block unlike in C/C++
# running = True
# while running:
#     max = input("Enter max: ")
#     print(max)
#     max = int(max)
#     for i in range(1, max+1):
#         print(f"{max} % {i} = {max % i}")
#     running = input("Again? y/n: ").lower()
#     print(running, end=" ")
#     print(running[:1], end=" ")
#     running = False if running[:1] != 'y' else True
#     print(running)  