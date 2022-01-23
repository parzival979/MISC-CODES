#include <iostream>
#include "functiontemplate.h"

int main(void){
    std::cout<<"PLEASE ENTER 1 FOR AN ARRAY OF INTEGERS,2 FOR DOUBLES,3 FOR CHARACTERS\n";
    int menuOption;
    std::cin>>menuOption;
    int* arrayInt=NULL;
    double* arrayDouble=NULL;
    char* arrayChar=NULL;
    std::cout<<"PLEASE ENTER THE SIZE OF THE ARRAY\n";
    int arraySize;
    std::cin>>arraySize;
    if(menuOption==1){
        arrayInt = new int[arraySize];
    }
    else if(menuOption==2){
        arrayDouble = new double[arraySize];
    }
    else if(menuOption==3){
        arrayChar = new char[arraySize];
    }
    if(arrayInt!=NULL){
        for (int i = 0; i < arraySize; ++i) {
            std::cout<<"PLEASE ENTER THE DATA FOR THE ARRAY\n";
            std::cin>>arrayInt[i];
        }
        std::cout<<"THE ENTERED ARRAY IS\n";
        printArray(arrayInt,arraySize);
        int* minMaxArray= maxMin(arrayInt,0,arraySize-1);
        std::cout<<"THE MIN AND MAX ARE "<<minMaxArray[1]<<" AND "<<minMaxArray[0]<<"\n";
        findSecondMax(arrayInt,0,arraySize-1);
    }
    else if(arrayChar!=NULL){
        for (int i = 0; i < arraySize; ++i) {
            std::cout<<"PLEASE ENTER THE DATA FOR THE ARRAY\n";
            std::cin>>arrayChar[i];
        }
        std::cout<<"THE ENTERED ARRAY IS\n";
        printArray(arrayChar,arraySize);
        char* minMaxArray= maxMin(arrayChar,0,arraySize-1);
        std::cout<<"THE MIN AND MAX ARE "<<minMaxArray[1]<<" AND "<<minMaxArray[0]<<"\n";
        findSecondMax(arrayChar,0,arraySize-1);
    }
    else if(arrayDouble!=NULL){
        for (int i = 0; i < arraySize; ++i) {
            std::cout<<"PLEASE ENTER THE DATA FOR THE ARRAY\n";
            std::cin>>arrayDouble[i];
        }
        std::cout<<"THE ENTERED ARRAY IS\n";
        printArray(arrayDouble,arraySize);
        double* minMaxArray= maxMin(arrayDouble,0,arraySize-1);
        std::cout<<"THE MIN AND MAX ARE"<<minMaxArray[1]<<" AND "<<minMaxArray[0]<<"\n";
        findSecondMax(arrayDouble,0,arraySize-1);
    }



}

