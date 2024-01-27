# importing the module
import socket
import time

# creating a socket and connection between the devices --> sock-stream is a connection oriented TCP
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

client.bind(("192.168.1.155", 8888))

while True:
    packet = "hello"
    client.sendto(packet.encode(), ("192.168.1.177", 8888))
    message, addr = client.recvfrom(2000)
    print(message)
    time.sleep(0.1)