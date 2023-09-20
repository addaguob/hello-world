user_string_input = input("Enter string: ")
user_string_input = user_string_input.replace("Enter string: ", '')
string_permutation = ''
list_of_string_permutations = []

for count in range(len(user_string_input)):
	new_string_list_of_bytes = list(user_string_input[count:] + user_string_input[:count])
	for each_index in range(len(new_string_list_of_bytes)):
		if each_index+1 < len(new_string_list_of_bytes):
			new_string_list_of_bytes[each_index], new_string_list_of_bytes[each_index+1] = \
				new_string_list_of_bytes[each_index+1], new_string_list_of_bytes[each_index]
		new_string = ''.join(each_byte for each_byte in new_string_list_of_bytes)
		if new_string not in list_of_string_permutations:
			list_of_string_permutations.append(new_string)
	
total_permutations = len(list_of_string_permutations)
count = 0
for each_string in list_of_string_permutations:
	print(f"{count+1}/{total_permutations}: {each_string}")
	count += 1

"""
god -g 1st loop
   ogd
   odg
   
   -o 2nd loop
   gdo
   ogd
   
   -d 3rd loop
   dgo
   gdo
"""