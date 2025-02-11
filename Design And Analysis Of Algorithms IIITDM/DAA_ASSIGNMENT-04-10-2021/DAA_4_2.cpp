#include<vector>
#include<iostream>
using namespace std;

//Declaring a class named array
class Array{
private:
    vector<int> a;
public:
    //Insertion of element into array
    void arrayEntry(int element)
    {
        a.push_back(element);
    }

    int size(){
        return a.size();
    }

    //Normal insertion sort(Using Linear Search)
    /*void insertionSort(int n){
        int key, j;
        for (int i = 0; i < n; i++){
            key = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > key){
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }*/

    //Functions to perform binary search on i-1 sized array and return the index
    int binarySearch(int l, int r, int x);
    void binaryInsertSort(int n);
    //Function to display array
    void displayArray(int n);   

};

int Array :: binarySearch(int l, int r, int x){
    int mid = l + (r - l) / 2;
    if (a[mid] > x){
        if(a[mid-1]<x && mid>0)
            return mid;
        else
            if(mid-1 >= l)
                return binarySearch(l, mid - 1, x);
            else
                return 0;
    }
    else if(a[mid]<x){
        if((a[mid+1]>x && mid<r))
            return mid+1;
        else
            if(r>=mid+1)
                return binarySearch(mid + 1, r, x);
            else
                return -1;
    }
    else{
        return mid;
    }
}

void Array :: binaryInsertSort(int n){
    int key;
    for (int i = 1; i < n; i++){
        key = a[i];
        int x = binarySearch(0,i-1,key);
        if(x==-1){
            a[i] = key;
        }
        else if(x>=0){
            for(int j=i;j>x;j--)
                a[j] = a[j-1];
            a[x] = key;
        }
        else{
            cout<<"Task failed!\n";
        }
    }
}
//Function to display array
void Array :: displayArray(int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}
int main(){
    Array A;
    int element,continuity=1;
    while(continuity){
        cout <<"Enter the a element: ";
        cin >> element;
        A.arrayEntry(element);
        cout<<"Press 1 to add another element else 0: ";
        cin>>continuity;
    }
    cout<<endl;
    /*cout<<"The entered array is: ";
    A.displayArray(A.size());*/
    A.binaryInsertSort(A.size());
    cout<<endl;
    cout<<" The sorted array is: ";
    A.displayArray(A.size());
    return 0;
}