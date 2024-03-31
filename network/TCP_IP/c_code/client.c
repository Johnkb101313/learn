#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if (argc < 3) {
		printf("you don't provide server <ip> <port>");
		return -1;
	}

	// check server ip
	// can't use 255.255.255.255 here, because inet_addr will return INADDR_NONE (usually -1) when input invalid.
	in_addr_t serverIP = inet_addr(argv[1]);
	if (serverIP == INADDR_NONE) {
		printf("server <ip> is invalid");
		return -1;	
	};

	// check server port
	in_port_t serverPort = atoi(argv[2]);
	if (serverPort < 1024) {
		printf("server <port> is invalid");
		return -1;
	}
	serverPort = htons(serverPort);

	// create a new socket for connection
	int client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		perror("socket");
		return -1;
	}

	// fill in serverInfo ready for connection
	struct sockaddr_in serverInfo = {0};
	serverInfo.sin_family = AF_INET;
	serverInfo.sin_port = serverPort;
	serverInfo.sin_addr.s_addr = serverIP;

	// connect to server (3-way handshake)
	if (connect(client_socket, (struct sockaddr *)&serverInfo,\	
				sizeof(struct sockaddr_in)) == -1)
	{
		perror("connect");
		close(client_socket);
		return -1;
	};

	// close that socket server (4-way handshake)
	close(client_socket);

	return 0;
}
