// Programmed By Sravanth Chowdary Potluri CS20B1006
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const* argv[])
{
	int sock = 0, valread, client_fd;
	struct sockaddr_in serv_addr;
	char* hello = "Hello from client";
	char buffer[1024] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((client_fd= connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr)))< 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	int received_int=0;
	int return_status = read(sock, &received_int, sizeof(received_int));
	received_int=ntohl(received_int);
	
	printf("The frames received are in this order\n");
	for(int i=0;i<received_int;i++){
		int frame_int=0;
		return_status=read(sock,&frame_int,sizeof(frame_int));
		printf("%c ",ntohl(frame_int));
	}
	printf("\nProcess completed\n");
	close(client_fd);
	return 0;
}