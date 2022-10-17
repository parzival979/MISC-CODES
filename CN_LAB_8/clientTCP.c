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
    c_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in client,other;
    client.sin_family=AF_INET;
    client.sin_port=htons(9001);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("connection error\n");
        exit(-1);
    }
    socklen_t ad;
    ad=sizeof(other);
    char msg[256];
    printf("please enter the phone number\n");
    scanf("%s",msg);
    send(c_sock,msg,sizeof(msg),0);

    int s_sock;
    s_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(9002);
    server.sin_addr.s_addr= inet_addr("127.0.0.1");
    if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("connection error\n");
        exit(-1);
    }
    listen(s_sock,5);
    socklen_t add;
    add=sizeof(other);
    int cd_sock;
    int len = sizeof(client);
    cd_sock=accept(s_sock,(struct sockaddr*)&client,&len);
    recv(cd_sock,&msg,sizeof(msg),0);
    printf("The Recieved OTP is: %s\n",msg);

    printf("Please enter the otp\n");
    scanf("%s",msg);
    send(c_sock,msg,sizeof(msg),0);

    recv(cd_sock,&msg,sizeof(msg),0);
    if(!strcmp(msg,"1")){
        printf("OTP Validation Successful\n");
    }
    else{
        printf("OTP Validation Unsuccessful\n");
    }


}


