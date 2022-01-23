//PROGRAM BY SRAVANTH CHOWDARY POTLURI CS20B1006
#include <iostream>
#include <vector>
#include <math.h>
//REQUIRED CLASS
class binary{
public:
    //DECIMAL NUMBERS
    int m,n;
    //BINARY NUMBERS AND RESULT IN BINARY
    std::vector<int> binaryM,binaryN,multiplication;

    void mnToBinary();

    //PRINT FUNCTION TO PRINT BINARY
    void printVector(std::vector<int> reqVector){
        for (int i = reqVector.size()-1; i >= 0; i-=1) {
            std::cout<<reqVector[i];
        }
    }
    void multiplyBinaryMn();
    std::vector<int> binaryAdder(std::vector<int> binary1,std::vector<int> binary2);
    int binaryToDecimal(std::vector<int> binaryNo);
};

//DECIMAL TO BINARY CONVERSION FUNCTION
void binary::mnToBinary(){
    int temp=m;
    while (temp!=0){
        if(temp%2==1){
            binaryM.push_back(1);
            temp/=2;
        }
        else{
            binaryM.push_back(0);
            temp/=2;
        }
    }
    temp=n;
    while (temp!=0){
        if(temp%2==1){
            binaryN.push_back(1);
            temp/=2;
        }
        else{
            binaryN.push_back(0);
            temp/=2;
        }
    }

}

//BINARY MULTIPLICATION FUNCTION
void binary::multiplyBinaryMn(){
    multiplication.push_back(0);
    for (int i = 0; i < binaryN.size(); ++i) {
        std::vector<int> temp;
        for (int j = 0; j < i; ++j) {
            temp.push_back(0);
        }
        for (int j = 0; j < binaryM.size(); ++j) {
            temp.push_back(binaryN[i] * binaryM[j]);
        }
        multiplication = binaryAdder(multiplication, temp);
    }
}

//BINARY ADDER TO ADD TWO BINARY NUMBERS
std::vector<int> binary::binaryAdder(std::vector<int> binary1, std::vector<int> binary2) {
    std::vector<int> temp1=binary1,temp2=binary2,temp;
    if(temp1.size()<temp2.size()){
        temp=temp1;
        temp1=temp2;
        temp2=temp;
        for (int i = 0; i < temp1.size()-temp2.size(); ++i) {
            temp2.push_back(0);
        }

    }

    int carry=0,sum=0;
    for (int i = 0; i < temp2.size(); ++i) {
        sum=carry+temp1[i]+temp2[i];
        if(sum==3){
            temp1[i]=1;
            carry=1;
            continue;
        }
        else if(sum==2){
            carry=1;
            temp1[i]=0;
            continue;
        }
        else if(sum==1){
            carry=0;
            temp1[i]=1;
            continue;
        }
        else if(sum==0){
            carry=0;
            temp1[i]=0;
            continue;
        }
    }
    if(carry==1){
        temp1.push_back(1);
    }

    return temp1;



}


//BINARY TO DECIMAL RECONSTRUCTOR
int binary::binaryToDecimal(std::vector<int> binaryNo) {
    int temp=0;
    for (int i = 0; i < binaryNo.size(); ++i) {
        temp+=binaryNo[i]*pow(2,i);
    }
    return temp;
}


//MAIN FUNCTION
int main(void){
    //REQUIRED OBJECT
    binary reqObject;
    //TAKING DECIMAL NUMBERS AS INPUT
    std::cout<<"PLEASE ENTER A POSITIVE NUMBER M\n";
    std::cin>>reqObject.m;
    std::cout<<"PLEASE ENTER A POSITIVE NUMBER N\n";
    std::cin>>reqObject.n;
    reqObject.mnToBinary();
    //OUTPUTTING BINARY NUMBERS
    std::cout<<"THE BINARY NUMBERS ARE\n";
    std::cout<<"M:";
    reqObject.printVector(reqObject.binaryM);
    std::cout<<"\n";
    std::cout<<"N:";
    reqObject.printVector(reqObject.binaryN);
    std::cout<<"\n";
    //PRINTING THE MULTIPLIED BINARY NUMBER
    reqObject.multiplyBinaryMn();
    std::cout<<"THE MULTIPLIED BINARY NUMBER IS:";
    reqObject.printVector(reqObject.multiplication);
    std::cout<<"\n";
    //PRINTING THE RECONSTRUCTED DECIMAL NUMBER FROM BINARY
    std::cout<<"THE RECONSTRUCTED DECIMAL NUMBER IS:"<<reqObject.binaryToDecimal(reqObject.multiplication)<<"\n";


}