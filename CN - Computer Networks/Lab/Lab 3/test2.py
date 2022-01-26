#!/usr/bin/env python3

def byte_stuff_msg(message,flag_seq,esc_seq):
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq).replace('011111', esc_seq+'011111')
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq)
#	print('count esc',message.count(esc_seq))
#	new_esc = f'{esc_seq}{esc_seq}'
	
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq)
#	print('after removing esc seq',stuffed_message)
#	stuffed_message = stuffed_message.replace(flag_seq, esc_seq+flag_seq)
#	print('after removing flag seq',stuffed_message)
	
#	print('default',stuffed_message)
#	print('alter  ',message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq))
	
	
	return message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq)

def byte_unstuff_msg(message,flag_seq,esc_seq):
	return message.replace(esc_seq+flag_seq,flag_seq).replace(esc_seq+esc_seq, esc_seq)

message = '01111110asdfsdf011111100111111001111110abcabcasdfasdfasdfabc'
flag_seq = '01111110'
esc_seq = 'abc'
print('Original            : ',message)
stuffed = byte_stuff_msg(message,flag_seq,esc_seq)
unstuffed = byte_unstuff_msg(stuffed,flag_seq,esc_seq)
print('BYTE stuffing     : ',stuffed)
print('BYTE unstuffing   : ',unstuffed)
print('Original          : ',message)
