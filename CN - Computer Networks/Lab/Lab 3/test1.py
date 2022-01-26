#!/usr/bin/env python3

def bit_stuff_msg(message,flag_seq):
	count = 0
	stuffed_message = ''
	for char in message:
		stuffed_message += char
		if flag_seq[count]==char:
			count+=1
		else:
			count=0
		if count==6:
			stuffed_message += '0'
			count = 0
	return stuffed_message

def bit_unstuff_msg(message,flag_seq):
	return message.replace(flag_seq+'0', flag_seq)
		
str = '011111111000000111111111'
str = '0111111111111010101111110'
flag_seq = '011111'
print(str)
stuffed = bit_stuff_msg(str, flag_seq)
print(stuffed)
unstuffed = bit_unstuff_msg(stuffed, flag_seq)
print(unstuffed)
