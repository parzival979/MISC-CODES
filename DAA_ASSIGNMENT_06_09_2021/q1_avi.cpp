#include<vector>
#include <climits>
#include<iostream>
using namespace std;

class Array{
    vector<int> array;
    public:
        void arrayEntry(int element){
            array.push_back(element);
        } 
        int findMax_1way(int n){
            if (n == 1){
                return array[0];
            }
            else
                return max(array[n - 1],findMax_1way(n - 1));
        } 
        int max(int a, int b){
            return (a > b) ? a : b; 
        }
        int findMax_2way(int low, int high){
            if (high - low <= 1){
                return (max(array[low], array[high]));    
            }
            else{
                int mid = (low + high)/2;
                int max1 = findMax_2way(low, mid);
                int max2 = findMax_2way(mid + 1, high);
                return (max(max1,max2));
            }

        }
        int findMax_3way(int low, int high){
            if (high - low <= 1){
                return (max(array[low], array[high]));    
            }
            else{
                int mid1 = low + (high - low)/3;
                int mid2 = high - (high - low)/3;
                int max1 = findMax_3way(low, mid1);
                int max2 = findMax_3way(mid1 + 1, mid2);
                int max3 = findMax_3way(mid2 + 1, high);
                int Max;
                if (max1 > (max(max2,max3))){
                    Max = max1;
                }
                else
                    Max = max(max2,max3);
                return Max;
            }
        }
        int findMax_kway(int low, int high, int k){
            if (high - low <= 1){
                return (max(array[low], array[high]));    
            }
            else{
                int mid[k - 1], max[k];
                for(int i = 0; i < k - 1; i++){
                    mid[i] = low + (i+1)*((high - low)/k);
                }
                max[0] = findMax_kway(low , mid[0], k);
                max[k - 1] = findMax_kway(mid[k - 2] + 1, high, k);
                for(int i = 1; i < k - 1; i++){
                    max[i] = findMax_kway(mid[i - 1] + 1, mid[i], k);
                }
                int Max = max[0];
                for(int i = 1; i < k;i++){
                    if (max[i] > Max) 
                    Max = max[i];
                }
                return Max;
            }
        }

};

int main(){
    Array arr;
    cout <<"This is a program to find Max in the array\n";
    int size, element, k;
    cout << "Please enter the size of the array: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        cout <<"Enter the array element: ";
        cin >> element;
        arr.arrayEntry(element);
    }
    cout<<"Please enter the value of k for the k way approach: ";
    cin >> k;
    cout << "Max using 1 way approach is " << arr.findMax_1way(size) << endl;
    cout << "Max using 2 way approach is " << arr.findMax_2way(0, size-1) << endl;
    cout << "Max using 3 way approach is " << arr.findMax_3way(0, size-1) << endl;
    if (k > 0){
        while(size % k != 0){
            arr.arrayEntry(INT_MIN);
            size++;    
        }
        cout << "Max using k way approach where k is " << k << " is " << arr.findMax_kway(0, size-1, k) << endl;
    }
    else {
        cout << "Please enter a valid k and try again." << endl;
    }
    
    return 0;
}