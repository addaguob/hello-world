largest = None
smallest = None
while True:
    num = input("Enter a number: ")
    if num == "done":
        break
    else:
        try:
            num = int(num)
            if largest == None:
                largest = num
                smallest = num
            else:
                if largest < num:
                    largest = num
                if smallest > num:
                    smallest = num
        except:
            print("Invalid input")

print("Maximum is", largest)
print("Minimum is", smallest)
