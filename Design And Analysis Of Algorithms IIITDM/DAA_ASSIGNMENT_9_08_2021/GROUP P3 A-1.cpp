#include<iostream>
#include <vector>

//Declaration of class
class minMaxProgram{
private:
    //declaring array as private to protect data
    std::vector<int> minMaxArray;
public:
    //function to insert an element into array
    void arrayAdder(int element){
        minMaxArray.push_back(element);
    }

    /*Logic 1: Assigning max and min as first element and updating them as we traverse and compare with other elements*/
    void linearFinder(void){
        int min,max,sMin,sMax;
        min=minMaxArray[0];
        max=minMaxArray[0];
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(minMaxArray[i]>max) {
                max = minMaxArray[i];
            }
            if(minMaxArray[i]<min) {
                min = minMaxArray[i];
            }
        }

        /*Creating a second array without min and max of original array*/
        std::vector<int> secondMinMaxArray;
        for (int i = 0; i <minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }

        /*Finding max and min for this array which will smax and smin*/
        if(secondMinMaxArray.size()!=0) {
            sMin = secondMinMaxArray[0];
            sMax = secondMinMaxArray[0];

            for (int i = 0; i < secondMinMaxArray.size(); ++i) {
                if (secondMinMaxArray[i] > sMax) {
                    sMax = secondMinMaxArray[i];
                }
                if (secondMinMaxArray[i] < sMin) {
                    sMin = secondMinMaxArray[i];
                }
            }
        }

        /*Printing the values*/
        if(secondMinMaxArray.size()!=0)
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n \n";
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n \n";

    }

    /*Logic 2: Splitting the array into 2(left and right), and recursively finding max and min*/
    void binaryMaxMin(int &max,int &min,std::vector<int> array,int l,int r){
        if(l-r==0){
            max=min=array[l];
        }
        else if(((l-r)==1||(l-r)==-1)){
            if(array[l]>=array[r]){
                max=array[l];
                min=array[r];
            }
            else{
                min=array[l];
                max=array[r];
            }
        }
        else{
            int maxL,maxR,minL,minR;
            //recursive calling of function
            binaryMaxMin(maxL,minL,array,l,((l+(r-1))/2));
            binaryMaxMin(maxR,minR,array,(((l+(r-1))/2)+1),r);
            //Comparing Max and Min of both sides and finalizing
            if(maxL>=maxR)
                max=maxL;
            else
                max=maxR;

            if(minL<=minR)
                min=minL;
            else
                min=minR;
        }
    }

    //Creating 2nd array and printing values
    void binary_finder(){
        int max,min,sMin,sMax;

        minMaxProgram::binaryMaxMin(max,min,minMaxArray,0,minMaxArray.size()-1);
        std::vector<int> secondMinMaxArray;
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }
        if(secondMinMaxArray.size()!=0){

            minMaxProgram::binaryMaxMin(sMax,sMin,secondMinMaxArray,0,secondMinMaxArray.size()-1);
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n \n";
        }
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n \n";
    }

    //Array printer used for checking the code when necessary
    void array_printer(){
        std::cout<<"THE ARRAY IS\n";
        for (int i = 0; i < minMaxArray.size(); ++i) {
            std::cout<<minMaxArray[i]<<" ";
        }
        std::cout<<"\n";
    }

    /*Logic 3: Assigning min and max as 1st elements Comparing 2 elements at a time*/
    void pairCompare(int &min,int &max, std::vector<int> minMaxArray, int size){
        int i;
        if(size%2 == 0){
            if(minMaxArray[0]>minMaxArray[1]){
                max = minMaxArray[0];
                min = minMaxArray[1];
            }
            else{
                max = minMaxArray[1];
                min = minMaxArray[0];
            }
            i = 2;
        }
        else{
            min = minMaxArray[0];
            max = minMaxArray[0];
            i = 1;
        }
        while(i<size){
            if(minMaxArray[i]>minMaxArray[i+1]){
                if (minMaxArray[i]>max) {
                    max=minMaxArray[i];
                }
                if(minMaxArray[i+1]<min){
                    min = minMaxArray[i+1];
                }
            }
            else{
                if (minMaxArray[i+1]>max) {
                    max=minMaxArray[i+1];
                }
                if(minMaxArray[i]<min){
                    min = minMaxArray[i];
                }
            }

            i=i+2;
        }
    }

    //    //Creating 2nd array and printing values
    void minMaxComp(){
        int max, min, sMax, sMin;
        std::vector<int> secondMinMaxArray;
        pairCompare(min,max,minMaxArray,minMaxArray.size());
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }
        if(secondMinMaxArray.size()!=0){
            pairCompare(sMin,sMax,secondMinMaxArray,secondMinMaxArray.size());
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n \n";
        }
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n \n";
    }
};

//main function
int main(void){
    std::cout  << "PLEASE ENTER THE ELEMENTS IN THE ARRAY\n";
    minMaxProgram requiredArray;
    int elements_entry = 1;
    while(elements_entry){
        if(elements_entry ==1){
            std::cout<<"PLEASE ENTER THE ELEMENT FOR THE ARRAY\n";
            int arrayElement;
            std::cin>>arrayElement;
            std::cout<<"\n";
            requiredArray.arrayAdder(arrayElement);
        }
        else{
            std::cout<<"Please choose an valid operation.\n";
        }
        std::cout<<"ENTER 1 IF YOU WANT ADD MORE ELSE 0\n";
        std::cin>>elements_entry;
    }
    requiredArray.array_printer();
    std::cout<<"THE EXTREMES FROM LINEAR FINDER ALGORITHM ARE\n";
    requiredArray.linearFinder();
    std::cout<<"THE EXTREMES FROM BINARY FINDER ALGORITHM ARE\n";
    requiredArray.binary_finder();
    std::cout<<"THE EXTREMES FROM PAIR COMP ALGORITHM ARE\n";
    requiredArray.minMaxComp();
    return 0;
}