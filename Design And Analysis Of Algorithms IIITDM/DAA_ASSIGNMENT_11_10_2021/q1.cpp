#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Array {
    vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        }
        void arrayPrinter(){
            for(int i = 0; i < array.size(); i++){
                cout << array[i] << " ";
            }
            cout <<"\n";
        }
        void insertionSort(int left, int right);
        void merge(int l, int m, int r);
        int min(int a, int b){
            return (a < b) ? a : b;
        }
        void hybridSort(int n);
};

void Array::insertionSort(int left, int right){
    for(int i = left + 1; i <= right; i++){
        int temp = array[i];
        int j = i - 1;
        while (j >= left && array[j] > temp){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

void Array::merge(int l, int m, int r){
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = array[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = array[m + 1 + i];
        
    int i = 0;
    int j = 0;
    int k = l;

    while(i < len1 && j < len2){
        if (left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < len1){
        array[k] = left[i];
        k++;
        i++;
    }
    while(j < len2){
        array[k] = right[j];
        k++;
        j++;
    }
    
}

void Array::hybridSort(int n){
    for(int i = 0; i < n; i+=20)
        insertionSort(i, min((i+19),(n-1)));
    for(int size = 20; size < n; size = 2*size){
        for (int left = 0; left < n;left += 2*size){
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),(n-1));

            if(mid < right)
                merge(left, mid, right);
        }
    }
}

int main(){
    Array arr;
    int size, element;
    cout << "Please enter the size of the array: ";
    cin >> size;
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        element = -500 + (rand() % 1000);
        arr.arrayEntry(element);
    }
    cout <<"The Array filled with random Numbers is: \n";
    arr.arrayPrinter();
    cout <<"Array after Hybrid Sort : \n";
    arr.hybridSort(size);
    arr.arrayPrinter();
    return 0;
}