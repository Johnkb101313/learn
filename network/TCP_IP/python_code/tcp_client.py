import socket

tcp_client_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

tcp_client_s.connect(("127.0.0.1", 8080))

while True:
    user_input = input("Insert something: ")
    tcp_client_s.send(user_input.encode("utf-8"))
    if user_input == ":exit":
        break

tcp_client_s.close()
