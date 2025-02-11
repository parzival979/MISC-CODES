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
    int s_sock;
    char msg[256];
    s_sock=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in server, other;
    server.sin_family=AF_INET;
    server.sin_port=htons(9001);
    server.sin_addr.s_addr= inet_addr("127.0.0.1");
    socklen_t add;
    bind(s_sock,(struct sockaddr*)&server,sizeof(server));
    add=sizeof(other);
    printf("waiting for phone number\n");
    recvfrom(s_sock,msg,sizeof(msg),0,(struct sockaddr*)&other,&add);
    printf("the phone number is:%s\n",msg);

    int c_sock;
    c_sock=socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in client;
    client.sin_family=AF_INET;
    client.sin_port=htons(9002);
    client.sin_addr.s_addr=inet_addr("127.0.0.1");
    socklen_t ad;
    ad=sizeof(other);
    char otp[10];
    rand_str(otp,5);
    sendto(c_sock,otp,sizeof(otp),0,(struct sockaddr*)&client,sizeof(client));
    printf("the sent otp is: %s\n",otp);

    recvfrom(s_sock,msg,sizeof(msg),0,(struct sockaddr*)&other,&add);
    if(!strcmp(msg,otp)){
        printf("Valid OTP Received\n");
        sendto(c_sock,"1",sizeof("1"),0,(struct sockaddr*)&client,sizeof(client));
    }
    else{
        printf("Invalid OTP Received\n");
        sendto(c_sock,"0",sizeof("0"),0,(struct sockaddr*)&client,sizeof(client));
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