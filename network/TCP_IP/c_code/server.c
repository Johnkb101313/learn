#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	// create a new socket
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		perror("socket");
		return -1;
	}

	// binding server info to socket
	struct sockaddr_in serverInfo = {0};
	serverInfo.sin_family = AF_INET;
	// port: 8080
	serverInfo.sin_port = 0x901F;
	// ip: 192.168.179.232
	serverInfo.sin_addr.s_addr = 0xE8B3A8C0;

	if (bind(socket_fd, (struct sockaddr *)&serverInfo,\
			sizeof(struct sockaddr_in)) == -1) {
		perror("bind");
		close(socket_fd);
		return -1;
	};

	// mark the socket as a passive socket
	if (listen(socket_fd, 5) == -1) {
		perror("listen");
		close(socket_fd);
		return 0;
	};

	struct sockaddr_in clientInfo = {0};
	socklen_t size = sizeof(struct sockaddr_in);

	int client_socket = accept(socket_fd, (struct sockaddr *)&clientInfo, &size);

	if (client_socket == -1) {
		perror("accept");
		close(socket_fd);
		return -1;
	}

	close(socket_fd);

	return 0;
}