#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<sys/un.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int socketFd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';

	socketFd = socket(AF_UNIX, SOCK_STREAM, 0);
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);

	result = connect(socketFd, (struct sockaddr *)&address, len);

	if(result == -1) {
		perror("oops: client1");
		exit(1);
	}

	write(socketFd, &ch, 1);
	read(socketFd, &ch, 1);
	printf("char form server = %c\n", ch);
	close(socketFd);

	return 0;
}
