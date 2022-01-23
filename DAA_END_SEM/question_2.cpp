// PROGRAM BY SRAVANTH CHOWDARY POTLURI,CS20B1006
#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int A[], int size);
void greedyKnapsack(int* weightArray,int profitObjects,int number,int maxWeight);

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;


    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];


    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;


    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}


void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    std::cout<<"\n";
}


void greedyKnapsack(int* weightArray,int profitObjects,int number,int maxWeight){
    //BEING GREEDY WITH RESPECT TO WEIGHT
    //CHO0SING THE LESSER WEIGHT OBJECTS FIRST TO MAXIMIZE THE NUMBER OF OBJECTS IE PROFIT
    //SORTING THE WEIGHT ARRAY
    mergeSort(weightArray,0,number-1);
    int weightRemaining = maxWeight;
    int profit = 0;
    for (int i = 0; i < number; ++i) {
        if(weightRemaining>=weightArray[i]){
            profit+=profitObjects;
            std::cout<<"ITEM OF WEIGHT "<<weightArray[i]<<" IS CHOSEN\n";
            weightRemaining-=weightArray[i];
        }
        else{
            break;
        }

    }
    std::cout<<"WEIGHT REMAINING IN THE KNAPSACK IS "<<weightRemaining<<"\n";
    std::cout<<"THE TOTAL PROFIT OF THE ITEMS IN THE KNAPSACK IS\n"<<profit<<"\n";
}



int main(void){
    int nos;
    std::cout<<"PLEASE ENTER THE NUMBER OF OBJECTS\n";
    std::cin>>nos;
    int maxWeight;
    std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
    std::cin>>maxWeight;
    int itemProfit;
    std::cout<<"PLEASE ENTER THE PROFIT OF ALL THE OBJECTS\n";
    std::cin>>itemProfit;
    int weight[nos];
    for (int i = 0; i < nos; ++i) {
        std::cout<<"PLEASE ENTER THE WEIGHT OF ITEM "<<i<<"\n";
        std::cin>>weight[i];
    }
    std::cout<<"THE ENTERED WEIGHT ARRAY IS\n";
    printArray(weight,nos);
    greedyKnapsack(weight,itemProfit,nos,maxWeight);
}