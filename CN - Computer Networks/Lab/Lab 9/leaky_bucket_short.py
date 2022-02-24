#!/usr/bin/env python3
# 19BCE245 - Aayush Shah

n, size = int(input("Enter number of packets: ")), list(map(int, input("Enter size of packets one by one: ").split()))
bSize, rate, store = int(input("Enter bucket size: ")), int(input("Enter output rate: ")), 0

print()
for i in range(n):
    if size[i] > bSize - store:
        print(f'Packet number {i+1} having size {size[i]} is discarded.\n')
    else:
        store += size[i]
        print(f'Bucket buffer size is {store} out of {bSize}')
    store -= rate
    print(f'Packets left in the buffer: {store}\n')
	
'''
sample input1: 

avg_arrival_rate=100
bucket_capacity=150
avg_transmission_rate=90
maximum_data=1000 

sample input2:
avg_arrival_rate=100
bucket_capacity=150
avg_transmission_rate=90
maximum_data=100
'''