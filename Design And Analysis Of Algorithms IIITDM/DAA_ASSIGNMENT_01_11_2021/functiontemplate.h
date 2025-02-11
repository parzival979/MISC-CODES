#include <iostream>
template <typename t>
t* maxMin(t* array,int start,int end){
    if(end-start == 0){
        t* maxMinArray = new t[2];
        maxMinArray[0]=array[start];
        maxMinArray[1]=array[start];
        return maxMinArray;
    }
    else if(end-start == 1){
        t* maxMinArray = new t[2];
        if(array[start] > array[end]){
            maxMinArray[0]=array[start];
            maxMinArray[1]=array[end];
        }
        else{
            maxMinArray[0]=array[end];
            maxMinArray[1]=array[start];
        }
        return maxMinArray;
    }
    else{
        t* maxMinArray1;
        t* maxMinArray2;
        maxMinArray1= maxMin(array,start,(start+end)/2);
        maxMinArray2= maxMin(array,((start+end)/2)+1,end);
        if(maxMinArray1[0]<maxMinArray2[0])
            maxMinArray1[0]=maxMinArray2[0];
        if(maxMinArray1[1]>maxMinArray2[1])
            maxMinArray1[1]=maxMinArray2[1];
        return maxMinArray1;
    }

}

template<typename t>
void printArray(t* array,int size){
    for (int i = 0; i < size; ++i) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<"\n";
}

template<typename t>
void findSecondMax(t* array,int start,int end){
    t* minMaxArray = maxMin(array,start,end);
    for (int i = 0; i <= end; ++i) {
        if(array[i]==minMaxArray[0]){
            array[i]=INT16_MIN;
        }

    }
    minMaxArray= maxMin(array,start,end);
    std::cout<<"THE SECOND MAXIMUM IS "<<minMaxArray[0]<<"\n";

}