# Alexander Daguob - BMI Calculator Solution to Udemy's BMI challenge

patient = {
    'px_kg': 0.0,
    'px_lbs': 0.0,
    'px_meter': 0.0,
    'px_feet_inches': '0\'0\"'
}


def get_numbers_only_of(weight_in_string):
    weight_num = ''
    for each_character in weight_in_string:
        if each_character.isnumeric() or each_character == '.':
            weight_num += each_character
    return float(weight_num)


def run_BMI_calc():
    print("__________________________")
    print("Body Mass Index Calculator")
    print("--------------------------")
    weight_input = (input("Enter weight in pounds (lbs) or kilograms (kg)\n"
                          "Example: 190lbs or 87kg \n"
                          "Enter weight: "))
    weight = get_numbers_only_of(weight_input)
    weight_type = 'lbs or kg'
    if ("lbs" or 'pound') in weight_input.lower():
        weight_type = 'lbs'
        patient['px_lbs'] = weight
        # 1 lb = 0.454 kg
        weight *= 0.454
        patient['px_kg'] = weight
    elif ('kg' or 'kilo') in weight_input.lower():
        weight_type = 'kg'
        # no need to convert _weight, it's already in kg
        weight_input = str(weight) + weight_type
        patient['px_kg'] = weight
    else:
        print("Weight is not specified in pounds (lbs) or kilograms (kg).")
        print("Enter weight like this example: 190 lbs or 190 pounds or 87kg.")
        return

# Getting height from user: numbers and letters
    height_input = input("Enter your height in meters or feet+inches.\n"
                         "Example: 1.78m or 5\'10\" or 5 ft 10 inches\n"
                         "Enter height: ")
    height = get_numbers_only_of(height_input)
    height_type = "meter or feet+inches"
    str_feet = "height in feet only"
    if ("m" or "meter") in height_input.lower():
        patient['px_meter'] = height
        height_type = 'm'
        # 1 foot is 0.3048 meter
        str_feet = patient['px_meter'] / 0.3048
        patient['px_feet_inches'] = str(str_feet.__floor__()) + '\'' + str(
            int((str_feet % str_feet.__floor__()) * 12)) + '\"'
    elif ("f" or "ft" or "feet") in height_input.lower() or "\'" in height_input:
        str_feet_inches = str(int(height))
        height_type = '\'\"'
        patient['px_feet_inches'] = str_feet_inches[0]
        patient['px_feet_inches'] += height_type[0]
        patient['px_feet_inches'] += str_feet_inches[1:]
        patient['px_feet_inches'] += height_type[1]
        patient['px_feet_inches'] = str(patient['px_feet_inches'])
        height = float(str_feet_inches[0]) * 0.3048
        height = height + ((float(str_feet_inches[1:]) / 12.0) * 0.3048)
        patient['px_meter'] = height.__round__(2)
    else:
        print("Height is not specified in meters or feet+inches.")
        print("Enter height like this example: 5f 10inches or 5\'10\" or 1.78meters.")
        return
    print(f"Height is {patient['px_meter']}m or {patient['px_feet_inches']} and weight is {weight_input}.")
    # BMI = weight in kilograms divided by height in meters squared
    print(f"BMI is {patient['px_kg']}kg divided by {patient['px_meter']}m squared.")
    BMI = weight / (height ** 2)
    print(f"BMI is {BMI:.2f}")
    if BMI <= 18.5:
        print(f"{BMI:.2f} is Underweight.")
    elif 18.5 <= BMI <= 24.9:
        print(f"{BMI:.2f} is normal weight.")
    elif 25 <= BMI <= 29.9:
        print(f"{BMI:.2f} is Overweight")
    else:
        print(f"{BMI:.2f} is Obese")


user_choice = ''
while ('n' or 'no') not in user_choice.lower():
    run_BMI_calc()
    user_choice = input("Start BMI Calculator? (y/n): ")
print("Exiting program...")
