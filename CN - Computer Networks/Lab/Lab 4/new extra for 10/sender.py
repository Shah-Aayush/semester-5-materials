import socket

s = socket.socket()

s.bind(('localhost', 9999))
s.listen(3)

while True:
    c, addr = s.accept()
    try:
        filename = c.recv(1024).decode()
        with open(f'images\\{filename}', 'rb') as file:
            c.send(file.read())
        print(c.recv(1024).decode())
    except:
        pass
    c.close()