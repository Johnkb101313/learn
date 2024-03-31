import os
import socket
import sys

def get_file_list():
	list_ = os.listdir(".")

	counter = 0
	for index,node in enumerate(list_):
		if not os.path.isfile(node):
			temp = list_[counter]
			list_[counter] = list_[index]
			list_[index] = temp
			counter += 1
	
	return list_[counter:]

def get_file_list_menu(file_list):
	file_list_string = ""

	for index,node in enumerate(file_list):
		file_list_string += str(index) + ":" + node + "\n"

	return file_list_string

server_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_s.bind(("", 8080))
server_s.listen(128)
new_s, client_info = server_s.accept()
print("(%s:%d) connected" % (client_info[0], client_info[1]))

file_list = []
file_list_menu = ""

# interactive
while True:
	client_menu_option = new_s.recv(1024).decode("utf-8")

	if client_menu_option == '0':
		file_list = get_file_list()
		print(file_list)
		file_list_menu = get_file_list_menu(file_list)
		new_s.send(file_list_menu.encode("utf-8"))
	elif client_menu_option == '1':
		print("waiting client to select a file")
		ret = new_s.recv(1024).decode("utf-8")
		print(file_list)
		user_selected_file = file_list[int(ret)]
		print("client selected: %s" % (user_selected_file))

		# file io
		with open(user_selected_file, mode="rb") as fd:
			file_size = os.fstat(fd.fileno()).st_size
			new_s.send((file_size).to_bytes(4, "big"))
			file_content = fd.read()
			new_s.send(file_content)
		new_s.send((4).to_bytes())
	elif client_menu_option == '2':
		new_s.close()
		print("client disconnected")
		break

server_s.close()
