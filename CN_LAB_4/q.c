#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void detect_herr(int* array,int num_data_bits,int parity,int menu_option);
int* gen_hcode(int* message,int num_data_bits,int parity);
int positional_remainder(int num,int pos);
void print_arr(int* arr,int num);
int get_dec(int *arr,int num);
int main(){
    printf("Please enter the number of bits in the message\n");
    int numBits;
    scanf("%d",&numBits);
    int message[numBits];
    printf("Please enter the message seperated by spaces\n");
    for (int i = 0; i < numBits; ++i) {
        scanf("%d",&message[i]);
    }
    int parity;
    printf("Please enter the parity,1 for odd,0 for even\n");
    scanf("%d",&parity);
    int menuOption;
    printf("Please enter the menu Option\n");
    scanf("%d",&menuOption);
    detect_herr(message,numBits,parity,menuOption);
}

int* gen_hcode(int* message,int num_data_bits,int parity){//parity is 1 for odd,0 for even
    int num_redundant_bits = 0;
    while (1){
        if((int)pow(2,num_redundant_bits)>=num_redundant_bits+num_data_bits+1)
            break;
        else
            num_redundant_bits++;
    }
    int redundant_bits_arr[num_redundant_bits];
    int current_power = 0 ;
    int *req_ans = (int *)malloc(sizeof(int)*(num_data_bits+num_redundant_bits));
    int data_ptr = 0;
    int par_ptr = 0;
    for (int i = 1; i <= num_data_bits+num_redundant_bits; ++i) {
        if(i == (int)pow(2,current_power)){
            req_ans[num_data_bits+num_redundant_bits-i]=0;
            par_ptr++;
            current_power++;
        }
        else{
            req_ans[num_data_bits+num_redundant_bits-i]=message[num_data_bits-data_ptr-1];
            data_ptr++;
        }
    }
    for (int i = 1; i <= num_redundant_bits; ++i) {
        int sum = 0;
        for (int j = 1; j <= num_data_bits+num_redundant_bits ; ++j) {
            if(positional_remainder(j,i))
                sum+=req_ans[num_data_bits+num_redundant_bits-j];
        }
        if(sum%2 == parity)
            redundant_bits_arr[i-1] = 0;
        else
            redundant_bits_arr[i-1] = 1;
    }
    current_power = 0;
    par_ptr = 0;
    for (int i = 1; i <= num_data_bits+num_redundant_bits; ++i) {
        if(i == (int)pow(2,current_power)){
            req_ans[num_data_bits+num_redundant_bits-i]=redundant_bits_arr[par_ptr];
            par_ptr++;
            current_power++;
        }
    }
    return req_ans;

}

void detect_herr(int* array,int num_data_bits,int parity,int menu_option){
    int num_redundant_bits = 0;
    while (1){
        if((int)pow(2,num_redundant_bits)>=num_redundant_bits+num_data_bits+1)
            break;
        else
            num_redundant_bits++;
    }
    srand(time(0));
    int redundant_bits_arr[num_redundant_bits];
    int * output_arr = gen_hcode(array,num_data_bits,parity);
    switch (menu_option) {
        case 1:
            break;
        case 2:{
            int a =  rand()%(num_data_bits+num_redundant_bits);
            printf("The randomly flipped bit is %d from the left\n",a);
            if(output_arr[a])
                output_arr[a]=0;
            else
                output_arr[a]=1;
            break;
        }
        case 3:{
            if(output_arr[num_data_bits+num_redundant_bits-1])
                output_arr[num_data_bits+num_redundant_bits-1]=0;
            else
                output_arr[num_data_bits+num_redundant_bits-1]=1;
            break;
        }
        case 4:{
            int a =  rand()%(num_data_bits+num_redundant_bits);
            int b =  rand()%(num_data_bits+num_redundant_bits);
            printf("the randomly flipped bits are %d %d from the left\n",a,b);
            if(output_arr[a])
                output_arr[a]=0;
            else
                output_arr[a]=1;
            if(output_arr[b])
                output_arr[a]=0;
            else
                output_arr[a]=1;
            break;
        }
        default:
            break;

    }
    for (int i = 1; i <= num_redundant_bits; ++i) {
        int sum = 0;
        for (int j = 1; j <= num_data_bits+num_redundant_bits ; ++j) {
            if(positional_remainder(j,i))
                sum+=output_arr[num_data_bits+num_redundant_bits-j];
        }
        if(sum%2 == parity)
            redundant_bits_arr[num_redundant_bits-i] = 0;
        else
            redundant_bits_arr[num_redundant_bits-i] = 1;
    }
    printf("The Faulty bit is bit %d from the right\n",get_dec(redundant_bits_arr,num_redundant_bits));
}

int positional_remainder(int num,int pos){
    while(1){
        pos--;
        if(pos==0){
            if(num%2==1)
                return 1;
            else
                return 0;
        }
        else{
            num/=2;
        }
    }
}

void print_arr(int* arr,int num){
    for (int i = 0; i < num; ++i) {
        printf("%d",arr[i]);
    }
}

int get_dec(int *arr,int num){
    int ans = 0;
    for (int i = 0; i < num; ++i) {
        ans+=(arr[i]*((int)pow(2,(num-i-1))));
    }
    return ans;
}
