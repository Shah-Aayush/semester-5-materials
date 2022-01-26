import socket

r = socket.socket()

try:
    r.connect(('localhost', 9999))

    filename = input('Enter a number from 1 to 5: ') + '.jpeg'

    r.send(bytes(filename, 'utf-8'))

    info = r.recv(1024*16)

    with open(f'recieved/{filename}', 'wb') as file:
        file.write(info)
    r.send(bytes(f'File {filename} recieved.', 'utf-8'))
    
except:
    print('Connection refused, try again.')