/* Question 3 : Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up 
to the given integer X.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Array{
    private:
        vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        }
        bool findTriplets(int sum){
            // Sort elements
            sort(array.begin(),array.end());
            int l,r;
            if (array.size() < 3){
                cout << "There're no triplets in the array as there're less than 3 elements present in the array" << endl;
            }
            else {
                // FIrst Fix the 1st by finding it one by one and then find the other 2 elements
                for(int i = 0; i < array.size() - 2; i++){
                    // To find other two we first fix corners and move one by obe to find the other 2 elements
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
    Array arr;
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
        cout <<"Triplets exists in the array that satisfy the sum \n";
    }
    else {
        cout << "No Triplets exists that satisfies the sum in the given array\n";
    }
    return 0;
}