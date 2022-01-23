#include<iostream>
#include<vector>
using namespace std;
class negativeArray_program
{
    private:
        vector<int>negativeArray;
    public:
        void insert(int data)
        {
            negativeArray.push_back(data);
        }
        void printArray()
        {
            cout<<"The array is:";
            for(int i=0;i<negativeArray.size();i++)
            {
                cout<<negativeArray[i]<<" ";
            }
            cout<<endl;
        }
        int twoway(int low,int high)
        {
            int negativeCount=0;
            if(low>high)
            {
                return 0;
            }
            else
            {
                if(low==high)
                {
                    if(negativeArray[low]<0)
                    {
                        negativeCount++;
                    }
                    return negativeCount;
                }
                else
                {
                    int mid=(low+high)/2;
                    int firsthalf=twoway(low,mid);
                    int secondhalf=twoway(mid+1,high);
                    
                    return (firsthalf+secondhalf);
                }
            }
        }
        int threeway(int low,int high)
        {
            int negativeCount=0;
            if(low>high)
            {
                return 0;
            }
            else
            {
                if(low==high)
                {
                    if(negativeArray[low]<0)
                    {
                        negativeCount++;
                    }
                    return negativeCount;
                }
                else
                {
                    int mid1=low+(high-low)/3;
                    int mid2=high-(high-low)/3;
                    int firsthalf=threeway(low,mid1);
                    int secondhalf=threeway(mid1+1,mid2-1);
                    int thirdhalf=threeway(mid2,high);
                    return(firsthalf+secondhalf+thirdhalf);
                }
            }
        }
        void functionCall()
        {
            int check=negativeArray.size(),i;
            for(i=1;i<=check;i*=2)
            {
            }
            if(i!=check)
            {
                while(check!=i)
                {
                    insert(0); check++;
                }
            }
            cout<<"The number of negative elements in the array using twoway is:"<<twoway(0,negativeArray.size()-1)<<endl;
            check=negativeArray.size();
            for(i=1;i<=check;i*=3)
            {
            }
            if(i!=check)
            {
                while(check!=i)
                {
                    insert(0); check++;
                }
            }
            cout<<"The number of negative elements in the array using threeway is:"<<threeway(0,negativeArray.size()-1)<<endl;
        }
};
int main()
{
    negativeArray_program array;
    int size,data;
    cout<<"Enter the size of array:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element:";
        cin>>data;
        array.insert(data);
    }
    array.printArray();
    array.functionCall();
    return 0;
}