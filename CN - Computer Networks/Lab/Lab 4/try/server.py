import socket
import os

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
#s.bind(('', )) if the clients/server are on different network you shall bind to ('', port)
s.bind(("", 12345)) #if the clients/server are on different network you shall bind to ('', port)

s.listen(10)
c, addr = s.accept()
print('{} connected.'.format(addr))

f = open("image.jpeg", "rb")
l = os.path.getsize("image.jpeg")
m = f.read(l)
c.send_all(m)
f.close()
print("Done sending...")