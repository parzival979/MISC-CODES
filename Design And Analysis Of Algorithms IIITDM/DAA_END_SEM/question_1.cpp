// PROGRAM BY SRAVANTH CHOWDARY POTLURI,CS20B1006
#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right);
void mergeSort(int array[], int const begin, int const end);
void printArray(int A[], int size);
void greedyKnapsack(int* profitArray,int weightObjects,int number,int maxWeight);

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

void greedyKnapsack(int* profitArray,int weightObjects,int number,int maxWeight){
    //BEING GREEDY WITH RESPECT TO PROFIT
    //CHOOSING ITEMS WITH HIGHER PROFIT THEREBY MAXIMIZING PROFIT
    //SORTING THE PROFIT ARRAY
    mergeSort(profitArray,0,number-1);
    int weightRemaining = maxWeight;
    int profit = 0;
    for (int i = number-1; i >=0 ; i-=1) {
        if(weightRemaining>=weightObjects){
            profit+=profitArray[i];
            std::cout<<"ITEM OF PROFIT "<<profitArray[i]<<" IS CHOSEN\n";
            weightRemaining-=weightObjects;
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
    int weight;
    std::cout<<"PLEASE ENTER THE MAXIMUM WEIGHT OF THE KNAPSACK\n";
    std::cin>>weight;
    int itemWeight;
    std::cout<<"PLEASE ENTER THE WEIGHT OF ALL THE OBJECTS\n";
    std::cin>>itemWeight;
    int profit[nos];
    for (int i = 0; i < nos; ++i) {
        std::cout<<"PLEASE ENTER THE PROFIT OF ITEM "<<i<<"\n";
        std::cin>>profit[i];
    }
    std::cout<<"THE ENTERED PROFIT ARRAY IS\n";
    printArray(profit,nos);
    greedyKnapsack(profit,itemWeight,nos,weight);
}