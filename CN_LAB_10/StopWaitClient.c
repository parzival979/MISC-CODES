// Programmed By Sravanth Chowdary Potluri CS20B1006
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int stop_wait(int arr[])
{
    int n,counter=0,i,j;
    char req_string[100];
    printf("please enter the string\n");
    scanf("%s",req_string);
    n = strlen(req_string);
    printf("enter lost acknowledgement number: ");
    scanf("%i",&j);
    for(i=1;i<j&&i<=n;i++)
    {
        arr[counter++]=req_string[i-1];
    }
    return counter;
}

int main(int argc, char const* argv[])
{
	int arr[100];
	int count=stop_wait(arr);
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };
	char* hello = "Hello from server";
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))== 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}


	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(server_fd, (struct sockaddr*)&address,sizeof(address))< 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket= accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen))< 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	int number_to_send=count;
	int converted_number = htonl(number_to_send);
	write(new_socket, &converted_number, sizeof(converted_number));
	
	printf("The frames are sent to client");
	for(int i=0;i<count;i++)
    {
		number_to_send=arr[i];
		converted_number=htonl(number_to_send);
		write(new_socket,&converted_number,sizeof(converted_number));
	}
	printf("\nProcess completed\n");
	
	close(new_socket);
	shutdown(server_fd, SHUT_RDWR);
	return 0;
}