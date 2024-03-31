import socket
import sys

tcp_client_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

tcp_client_s.connect(("192.168.217.232", 8080))

while True:
	menu_option = input("0:List all files\n1:Download file\n2:Leave\nEnter a list number: ")

	if menu_option == '0':
		tcp_client_s.send('0'.encode("utf-8"))
		print(tcp_client_s.recv(1024).decode("utf-8"))
	elif menu_option == '1':
		tcp_client_s.send('1'.encode("utf-8"))
		file_selection = input("Enter a file number: ")
		tcp_client_s.send(file_selection.encode("utf-8"))
		file_size = int.from_bytes(tcp_client_s.recv(1024))
		save_path = input("path?: ")
		file_content = ""
		readed_bytes = 0
		while readed_bytes < file_size:
			file_content = tcp_client_s.recv(1024)
			with open(save_path, mode="ab") as fd:
				fd.write(file_content)
			readed_bytes += 1024
		print("file download successful!")
	elif menu_option == '2':
		tcp_client_s.send('2'.encode("utf-8"))
		break

tcp_client_s.close()
