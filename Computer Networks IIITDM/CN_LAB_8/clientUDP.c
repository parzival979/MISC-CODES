//Code by Sravanth Chowdary Potluri CS20B1006

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int c_sock;
    char msg[256];
    c_sock=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in client,other;
    client.sin_family=AF_INET;
    client.sin_port=htons(9001);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    socklen_t ad;
    ad=sizeof(other);
    printf("please enter the phone number\n");
    scanf("%s",msg);
    sendto(c_sock,msg,sizeof(msg),0,(struct sockaddr*)&client,sizeof(client));

    int s_sock;
    s_sock=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(9002);
    server.sin_addr.s_addr= inet_addr("127.0.0.1");
    socklen_t add;
    bind(s_sock,(struct sockaddr*)&server,sizeof(server));
    add=sizeof(other);
    recvfrom(s_sock,msg,sizeof(msg),0,(struct sockaddr*)&other,&add);
    printf("The Recieved OTP is: %s\n",msg);

    printf("Please enter the otp\n");
    scanf("%s",msg);
    sendto(c_sock,msg,sizeof(msg),0,(struct sockaddr*)&client,sizeof(client));

    recvfrom(s_sock,msg,sizeof(msg),0,(struct sockaddr*)&other,&add);
    if(!strcmp(msg,"1")){
        printf("OTP Validation Successful\n");
    }
    else{
        printf("OTP Validation Unsuccessful\n");
    }


}


