import socket

tcp_server_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

tcp_server_s.bind(("", 8080))

tcp_server_s.listen(128)

# wait for an incoming connection.
# return a new socket representing the connection, and the address of the client
# For IP sockets, the address info is a pair (hostaddr, port)
new_s, client_info = tcp_server_s.accept()
# 所以現在有了兩個socket, 兩個socket之間互相獨立, 所以一個關閉(.close())不會影響另一個
# 即現在如果tcp_server_s的這個用來listen的socket一但關閉, 此前已透過該socket建立connection((.accept()))所創建的這個socket不會受到影響

print(client_info)
print("connect")


while True:
    # client side運行了socket.close()以後，recv(...)會返回空數據
    # 你可能認為client side能夠發送空數據以越過這個detection，但其實:
    # TCP 因為不允許發送空數據，因此這種detection有效
    ret = new_s.recv(1024)
    if len(ret) == 0:
        print("client exited!")
        break
    print(ret.decode("utf-8"))

tcp_server_s.close()
