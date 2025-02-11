/* Question 3 : Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up 
to the given integer X.*/
#include <iostream>
#include <vector>
using namespace std;

class array{
    private:
        vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        }

        void swap(int* x, int* y){ 
            int temp = *x; 
            *x = *y; 
            *y = temp; 
        }

        int partition(int l, int h) { 
            int pivot = array[h]; // setting pivot 
            int i = (l - 1); // Index of smaller element and indicates the right corner of pivot found so far
            for (int j = l; j <= h - 1; j++) { 
                // If current element is smaller than the pivot 
                if (array[j] < pivot) { 
                    i++; // increment index of smaller element 
                    swap(&array[i], &array[j]); 
                } 
            } 
            swap(&array[i + 1], &array[h]); 
            return (i + 1);
        } 

        void qSort(int l, int h){
            if (l < h) { 
                int p = partition(l, h); // partitioning index
                // Separately sort elements before partition and after partition 
                qSort(l, p - 1); 
                qSort(p + 1, h); 
            } 
        }

        bool findTriplets(int sum){
            // Sort the elements of the array by quicksort
            qSort(0, array.size() - 1);
            if (array.size() < 3){
                cout << "There're no triplets in the array as there're less than 3 elements present in the array" << endl;
            }
            else{
                int l,r;
                // FIrst Fix the 1st by finding it one by one and then find the other 2 elements
                for(int i = 0; i < array.size() - 2; i++){
                    // To find other two we first fix corners and move one by one to find the other 2 elements
                    l = i + 1; // index of first in the remaining elements
                    r = array.size() - 1; // index of last in the remaining elements
                    while(l < r){
                        // Return true and print out the triplets if found
                        if (array[i] + array[l] + array[r] == sum) { 
                            cout << "Triplets are " << array[i] << ", " << array[l] << ", " << array[r] << endl; 
                            return true; 
                        } 
                        // If sum is less we move the corners to the right to get greater elements
                        else if (array[i] + array[l] + array[r] < sum) 
                            l++;
                        // If sum is more we move the corners to the left the get lower elements
                        else if (array[i] + array[l] + array[r] > sum) 
                            r--;    
                    } 
                }
            }    
            // Return false if no triplet found 
            return false;
        }

};

int main(){
    array arr;
    cout <<"This is a program to tell whether there is a triplet in the given array that satisfies the sum given \n";
    int choice = 1, sum;
    while (choice){
        if (choice == 1){
            cout << "Please enter the element to be added to the array: \n";
            int element;
            cin >> element;
            arr.arrayEntry(element);
        }
        else{
            cout << "Please enter a valid choice\n";
        }
        cout << "Enter 1 if you want to add more else 0 \n";
        cin >> choice;
    }
    cout<<"Please enter the sum you want to find if there're any triplets in the given array that satify the given sum \n";
    cin >> sum;
    if(arr.findTriplets(sum)){
        cout <<"Triplets exists in the array that satisfies the sum \n";
    }
    else {
        cout << "No Triplets exists that satisfies the sum in the given array\n";
    }
    return 0;
}