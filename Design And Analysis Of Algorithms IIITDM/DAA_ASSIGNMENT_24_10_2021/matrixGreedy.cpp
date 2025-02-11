#include <bits/stdc++.h>
#include <climits>
using namespace std;

/*
Aim: "To reduce the cost of multiplication of matrices"
Strat employed: "If we first multiply adjacent matrices with low cost we get overall low cost".

cases we get Optimal output: {1,5,4,2} || {1,5,4,2,5} ||{1,8,2,7,3,6,4,5} || ........

feasible but non-optimal solutions: {5,4,2,3,5}(Strat gives 159, optimal is 120.) || { 7 ,5 ,3 ,6 ,5 ,4}{stat gives 470 but optimal is 339 } || {2 1 2 5}(strat gives 24, optimal is 20) ..............
*/

class matrixMult{
private:
    vector <int> arr;
    int cost =0;

public:
    //function to add an element to the vector
    void add(int a){
        arr.push_back(a);
    }
    
    //function to find the cost of the multiplication of matrices
    void mult(int n){
        //a is cost for adjacent matrix multiplication, b is the minimum cost among all adjacent pairs, cost is cost obv. 
        //if input has more than 2 matrices
        if(n>3){
            //for 1st iteration a is the minimum for all calculated pairs so b is initialized as intmax.
            int a,b=INT16_MAX,mid;
            //for loop to find min cost of all adjacent pairs and mid element of leastCostPair which will be deleted after multiplication
            for(int i=0;i<n-2;i++){
                a=arr[i]*arr[i+1]*arr[i+2];
                //cout<<a<<" and "<<b<<endl;
                if(a<b){
                    swap(a,b);
                    mid=i+1;
                }
            }
            //incrementing cost by least cost among all adjacent pairs.
            cost=cost+b;

            //for loop to delete mid element and shift all elements forward
            for(int i=mid;i<n;i++){
                arr[i]=arr[i+1];
            }

            /*
            //check the array after deleting
            for(int i=0;i<n-1;i++){
                cout<<arr[i]<<" ";
            }*/
            cout<<endl;
            //calling the same function recursively after deleting mid element so now size will be n-1
            mult(n-1);
        }

        //if we have only 2 matrices so we will have only one way to multiply them so cost is directly multiplication of all 3 remaining array elements.
        else if(n==3){
            cost = cost + arr[0]*arr[1]*arr[2];
            cout<<"The cost of the multiplication is: "<<cost;
        }

    }
};

int main(){
    matrixMult obj;
    int n,x;
    cout << "Enter the number of matrix orders: ";
    cin >> n;

    int arr[n];
    cout << "Enter the orders: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        x =arr[i];
        obj.add(x);
    }
    obj.mult(n);
    cout << endl;

    return 0;
}