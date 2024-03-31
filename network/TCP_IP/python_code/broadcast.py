import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

s.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)

s.sendto("hello world".encode("utf-8"), ("<broadcast>", 8080))

s.close()
