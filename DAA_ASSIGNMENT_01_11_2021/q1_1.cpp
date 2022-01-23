#include<iostream>
#include<vector>
using namespace std;

class dpCoin {
    private:
        vector<int>coinArray;
    public:
        void arrayEntry(int data){
            coinArray.push_back(data);
        }
        void Display(){
            for(int i = 0; i < coinArray.size(); i++){
                cout<<coinArray[i] << " ";
            }
            cout<<" \n";
        }
        int coinChange(int amount){
            vector<int>ways(amount + 1);
            ways[0] = 1;
            for(int i = 0; i < coinArray.size(); i++){
                for(int j = 0; j < ways.size(); j++){
                    if(coinArray[i] <= j){
                        ways[j] += ways[(j - coinArray[i])];
                    }
                }
            }
            return ways[amount];
        }
};

int main() {
    int size, element, amount, ways;
    dpCoin object;
    cout<<"Enter the size of the Denominations array:";
    cin>>size;
    for(int i = 0; i < size; i++){
        cout<<"Enter the denomination: ";
        cin >> element;
        object.arrayEntry(element);
    }
    cout<<"Now enter the amount you want to find ways of denominations of: ";
    cin >> amount;
    cout<<"The given denominations array is: \n";
    object.Display();
    ways = object.coinChange(amount);
    cout<<"The number of ways(combinations) using the denominations to get the given amount is: "<< ways << "\n";
    return 0;
}