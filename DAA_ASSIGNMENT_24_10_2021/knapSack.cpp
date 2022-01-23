#include<iostream>
#include<vector>
using namespace std;
class greedyKnap
{
    private:
        vector<int>weightArray;
        vector<int>profitArray;
        vector<float>counterArray;
    public:
        void add(int data,int data2)
        {
            weightArray.push_back(data);
            profitArray.push_back(data2);
        }
        void display()
        {
            for(int i=0;i<weightArray.size();i++)
            {
                cout<<weightArray[i]<<" ";
            }
            cout<<'\n';
            for(int i=0;i<profitArray.size();i++)
            {
                cout<<profitArray[i]<<" ";
            }
            cout<<'\n';
        }
        void profitSort()
        {
            for(int i=0;i<profitArray.size()-1;i++)
            {
                for(int j=i;j<profitArray.size();j++)
                {
                    if(profitArray[i]<profitArray[j])
                    {
                        int temp=profitArray[i]; profitArray[i]=profitArray[j]; profitArray[j]=temp;
                        temp=weightArray[i]; weightArray[i]=weightArray[j]; weightArray[j]=temp;
                    }
                }
            }
        }
        void weightSort()
        {
            for(int i=0;i<profitArray.size()-1;i++)
            {
                for(int j=i;j<profitArray.size();j++)
                {
                    if(weightArray[i]>weightArray[j])
                    {
                        int temp=profitArray[i]; profitArray[i]=profitArray[j]; profitArray[j]=temp;
                        temp=weightArray[i]; weightArray[i]=weightArray[j]; weightArray[j]=temp;
                    }
                }
            }
        }
        void mixedSort()
        {
            for(int i=0;i<profitArray.size()-1;i++)
            {
                for(int j=i;j<profitArray.size();j++)
                {
                    if(profitArray[i]/weightArray[i]<profitArray[j]/weightArray[j])
                    {
                        int temp=profitArray[i]; profitArray[i]=profitArray[j]; profitArray[j]=temp;
                        temp=weightArray[i]; weightArray[i]=weightArray[j]; weightArray[j]=temp;
                    }
                }
            }
        }
        void knapSack(int maxWeight)
        {
            int counter=0;
            for(int i=0;i<weightArray.size()&&counter!=maxWeight;i++)
            {
                    if(counter+weightArray[i]>=maxWeight)
                    {
                        float x=((float)(maxWeight-counter)/weightArray[i]);
                        counterArray.push_back(x);
                        counter=maxWeight;
                    }
                    else
                    {
                        counter+=weightArray[i];
                        counterArray.push_back(1);
                    }
            }
            float profit=0;
            for(int i=0;i<counterArray.size();i++)
            {
                profit+=profitArray[i]*counterArray[i];
                if(counterArray[i]>0)
                {
                    if(counterArray[i]==1)
                    {
                        cout<<" 1 unit of object with weight "<<weightArray[i]<<" and profit "<<profitArray[i]<<endl;
                    }
                    else 
                    {
                        cout<<counterArray[i]<<" units of object with weight "<<weightArray[i]<<" and profit "<<profitArray[i];
                    }
                }
            }
            cout<<'\n';
            cout<<"The maximum profit is:"<<profit<<endl;
        }
};
int main()
{
    greedyKnap object;
    int size,weight,profit,maxWeight,choice;
    cout<<"Enter the number of objects:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the weight and profit of the object:";
        cin>>weight>>profit;
        object.add(weight,profit);
    }
    cout<<"Enter the maximum weight of the basket:";
    cin>>maxWeight;
    cout<<"Enter what type of greedy strategy you want:"<<endl;
    cout<<"If w.r.t weight enter 1 else if w.r.t profit enter 2 else if w.r.t profit/weight enter 3:";
    cin>>choice;
    switch(choice)
    {
        case 1:
            object.weightSort();
            break;
        case 2:
            object.profitSort();
            break;
        case 3:
            object.mixedSort();
            break;
        default:
            cout<<"Not a valid choice"<<endl;
            return 0;
    }
    cout<<"The result is:";
    object.knapSack(maxWeight);
    return 0;
}