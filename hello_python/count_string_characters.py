user_string_input = input("Enter string: ")
user_string_input = user_string_input.replace("Enter string: ", '')
total_byte_in_string_input = len(user_string_input)
byte_dict = {}
for byte in user_string_input:
	byte_dict[byte] = 0;
	
for byte in user_string_input:
	for key in byte_dict:
		if byte == key:
			byte_dict[key] += 1
			
for key in byte_dict:
	print(f"{key}-{byte_dict[key]}")
	
	
	
