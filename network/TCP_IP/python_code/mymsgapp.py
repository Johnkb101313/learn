import socket

# create a socket
# ipv4
# udp
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# bind ip port
local_info = ("", 8080)
# ip address version: ipv4
# udp
# ip address: 192.168.187.232
# port: 8080

s.bind(local_info)

print("SERVER INFO: %s:%d" % (local_info[0], local_info[1]))

last_msg = ("", ("", 0))

while(1):
    print("[1] receive msg")
    print("[2] send msg")
    menu_option = input("[1] or [2]: ")

    if menu_option == '1':
        receive_msg = s.recvfrom(1024)
        if receive_msg[1][0] != last_msg[1][0] or receive_msg[1][1] != last_msg[1][1]:
            print("\nmsg come from: %s:%d" % (receive_msg[1][0], receive_msg[1][1]))
        print("%s" % receive_msg[0].decode("utf-8"))
    elif menu_option == '2':
        usr_input = input("Insert something: ")
        s.sendto(usr_input.encode("utf-8"), (receive_msg[1][0], receive_msg[1][1]))

    last_msg = receive_msg

s.close()
