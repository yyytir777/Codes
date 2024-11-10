
encoded_str = "EDVLF FUBSWR GUHDPKDFN"

decoded_str_list = []
decoded_str = ""
for j in range(26):
    for i in encoded_str:
        if i == " ":
            decoded_str += "_"
        else:
            shifted = ord(i) + j    
            if shifted > ord('Z'):
                shifted -= 26
            decoded_str += chr(shifted)

    decoded_str_list.append(decoded_str)
    decoded_str = ""

for temp in decoded_str_list:
    print(temp)