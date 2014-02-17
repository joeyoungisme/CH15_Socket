#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<sys/un.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int ServerSocketFd, ClientSocketFd;
	int ServerLen, ClientLen;
	
	struct sockaddr_un ServerAddress;
	struct sockaddr_un ClientAddress;

	unlink("Server_Socket");
	ServerSocketFd = socket(AF_UNIX, SOCK_STREAM, 0);
	ServerLen = sizeof(ServerAddress);
	bind(ServerSocketFd, (struct sockaddr *)&ServerAddress, ServerLen);
	listen(ServerSocketFd, 5);
	while(1) {
		char ch;

		printf("Server Waiting\n");

		ClientLen = sizeof(ClientAddress);
		ClientSocketFd = accept(ServerSocketFd, \
				(struct sockaddr *)&ClientAddress, &ClientLen);
		read(ClientSocketFd, &ch, 1);
		ch++;
		write(ClientSocketFd, &ch, 1);
		close(ClientSocketFd);

	}

	return 0;
}

