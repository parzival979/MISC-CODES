//Programmed By CS20B1006 Sravanth Chowdary Potluri

#include<stdio.h>
#include<ctype.h>
#include<math.h>

void IntToBinary(int n[4], int b[32]) {
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i * 8 + 7; j >= i * 8; j--) {
            if (n[i] % 2 == 0) b[j] = 0;
            else b[j] = 1;
            n[i] /= 2;
        }
}

void BinaryToInt(int b[32]) {
    int n, i, j;
    for (i = 0; i < 4; i++) {
        for (n = 0, j = i * 8; j <= i * 8 + 7; j++) {
            n *= 2;
            n += b[j];
        }
        printf("%i", n);
        if (i != 3) printf(".");
    }
}

int main() {
    char ip[16];
    int num[4] = {0, 0, 0, 0}, i, flag = 0, possible, bits[32], sub, j;
    printf("enter network ID: ");
    scanf("%s", ip);
    for (i = 0; ip[i] != '\0'; i++)
        if (flag == 4) {
            printf("invalid IP address");
            return 0;
        } else if (ip[i] == '.') {
            if (ip[i + 1] == '.' || ip[i + 1] == '\0') {
                printf("invalid IP address");
                return 0;
            } else flag++;
        } else if (isdigit(ip[i])) {
            num[flag] *= 10;
            num[flag] += ip[i] - 48;
        } else {
            printf("invalid IP address");
            return 0;
        }
    if (flag != 3) {
        printf("invalid IP address");
        return 0;
    }
    for (i = 0; i < 4; i++)
        if (num[i] > 255) {
            printf("invalid IP address");
            return 0;
        }
    if (num[0] == 0 || num[0] == 127) {
        printf("IP address does not belong to any class");
        return 0;
    } else if (num[0] < 127) possible = 23;
    else if (num[0] < 192) possible = 15;
    else if (num[0] < 224) possible = 7;
    else {
        printf("class of given network ID cannot have subnets");
        return 0;
    }
    IntToBinary(num, bits);
    for (i = 0; i <= possible; i++)
        if (bits[31 - i] == 1) {
            printf("given network ID is not valid");
            return 0;
        }
    printf("enter number of subnets: ");
    scanf("%i", &sub);
    for (i = 1; i <= possible; i++)
        if (pow(2, i) == sub) break;
    if (i > possible) {
        printf("number of subnets is not valid");
        return 0;
    }
    printf("total number of IP addresses in class is %lf\n", pow(2, possible + 1));
    printf("total number of hosts per subnet is %lf\n", pow(2, possible + 1) / sub);
    sub = log2(sub);
    printf("Interface\tSubnet ID\t\tDirected broadcast address\n");
    printf("1\t\t");
    BinaryToInt(bits);
    for (i = 31 - possible + sub; i < 32; i++)
        bits[i] = 1;
    printf("\t\t");
    BinaryToInt(bits);
    printf("\n");
    for (i = 1; i < pow(2, sub); i++) {
        for (j = 31 - possible + sub; j < 32; j++)
            bits[j] = 0;
        printf("%i\t\t", i + 1);
        for (j = 30 - possible + sub; bits[j] == 1; j--)
            bits[j] = 0;
        bits[j] = 1;
        BinaryToInt(bits);
        for (j = 31 - possible + sub; j < 32; j++)
            bits[j] = 1;
        printf("\t\t");
        BinaryToInt(bits);
        printf("\n");
    }
    for (i = 31 - possible + sub; i < 32; i++)
        bits[i] = 0;
    for (i = 30 - possible + sub; i >= 0; i--)
        bits[i] = 1;
    printf("subnet mask is ");
    BinaryToInt(bits);
    return 0;
}
