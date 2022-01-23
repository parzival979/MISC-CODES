#include<iostream>
#include<vector>
using namespace std;
class greedyCoin
{
    private:
        vector<int>coinArray;
        vector<int>denomination;
    public:
        void add(int data)
        {
            coinArray.push_back(data);
        }
        void display()
        {
            for(int i=0;i<coinArray.size();i++)
            {
                cout<<coinArray[i]<<" ";
            }
            cout<<'\n';
        }
        void bubbleSort()
        {
            for(int i=0;i<coinArray.size()-1;i++)
            {
                for(int j=i;j<coinArray.size();j++)
                {
                    if(coinArray[i]<coinArray[j])
                    {
                        int temp=coinArray[i]; coinArray[i]=coinArray[j]; coinArray[j]=temp;
                    }
                }
            }
        }
        int coinChange(int amount)
        {
            for(int i=0;i<coinArray.size();i++)
            {
                if(amount>0)
                {
                    if(amount>=coinArray[i])
                    {
                        int x=amount/coinArray[i]; 
                        denomination.push_back(x);
                        amount-=x*coinArray[i];
                    }
                    else 
                    {
                        denomination.push_back(0);
                    }
                }
                else 
                {
                    return 0;
                }
            }
            return amount;
        }
        void displayResult()
        {
            for(int i=0;i<denomination.size();i++)
            {
                if(denomination[i]>0)
                {
                    if(denomination[i]>1)
                    cout<<denomination[i]<<" Notes of "<<coinArray[i]<<",";
                    else 
                    cout<<denomination[i]<<" Note of "<<coinArray[i]<<",";
                }
            }
            cout<<'\n';
        }
};
int main()
{
    int size,elements,amount;
    greedyCoin array;
    cout<<"Enter the size of the array:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the denominations:";
        cin>>elements;
        array.add(elements);
    }
    cout<<"Now enter the amount you want:";
    cin>>amount;
    array.bubbleSort();
    amount=array.coinChange(amount);
    if(amount==0)
    { cout<<"The result is:"; array.displayResult();}
    else 
    {
        cout<<"Sorry the required amount cannot be given due to inadequate denominations"<<endl;
    }
    return 0;
}