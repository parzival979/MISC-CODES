//Code by Sravanth Chowdary Potluri CS20B1006
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <string.h>

void rand_str(char *dest, size_t length);

int main()
{
    char msg[256];
    int s_sock;
    struct sockaddr_in client,other;
    s_sock=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_port=htons(9001);
    server.sin_addr.s_addr= inet_addr("127.0.0.1");
    if(bind(s_sock,(struct sockaddr*)&server,sizeof(server))==-1)
    {
        printf("connection error\n");
        exit(-1);
    }
    printf("waiting for phone number\n");
    listen(s_sock,5);
    socklen_t add;
    add=sizeof(other);
    int cd_sock;
    int len = sizeof(client);
    cd_sock=accept(s_sock,(struct sockaddr *)&client, &len);
    recv(cd_sock,&msg,sizeof(msg),0);
    printf("the phone number is:%s\n",msg);

    int c_sock;
    c_sock=socket(AF_INET,SOCK_STREAM,0);
    client.sin_family=AF_INET;
    client.sin_port=htons(9002);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(connect(c_sock,(struct sockaddr*)&client,sizeof(client))==-1)
    {
        printf("connection error\n");
        exit(-1);
    }
    socklen_t ad;
    ad=sizeof(other);
    char otp[10];
    rand_str(otp,5);
    send(c_sock,otp,sizeof(otp),0);
    printf("the sent otp is: %s\n",otp);

    recv(cd_sock,&msg,sizeof(msg),0);
    if(!strcmp(msg,otp)){
        printf("Valid OTP Received\n");
        send(c_sock,"1",sizeof("1"),0);
    }
    else{
        printf("Invalid OTP Received\n");
        send(c_sock,"0",sizeof("0"),0);
    }
}

void rand_str(char *dest, size_t length) {
    srand(time(NULL));
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}