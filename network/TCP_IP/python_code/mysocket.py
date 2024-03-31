import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# send_port = input("port: ")
# send_port = int(send_port)

# 同一個socket不能重複bind多一次

while(1):
    send_msg = input("insert something: ")
    s.sendto(send_msg.encode("utf-8"), ("192.168.217.232", 8080))

s.close()
