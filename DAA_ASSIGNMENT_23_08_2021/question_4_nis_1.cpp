#include<iostream>
#include<vector>
using namespace std;
class subarrayprogram
{
    private:
        vector<int>subarray;
    public:
        void push(int data)
        {
            subarray.push_back(data);
        }
        void printarray()
        {
            for(int i=0;i<subarray.size();i++)
            {
                cout<<subarray[i]<<" ";
            }
        }
        void resultfinder()
        {
            int subarray_sum=0;
            int size=subarray.size();
            for(int i=0;i<size;i++)
            {
               subarray_sum+=(subarray[i]*(i+1)*(size-i));
            }
            cout<<"the required sum of all the subarray is:"<<subarray_sum;
        }
};
int main()
{
    int data;
    subarrayprogram array;
    int flag=1;
    while(flag)
    {
        if(flag==1)
        {cout<<"enter array element"<<":";
        cin>>data;
        array.push(data);}
        else{
            cout<<"enter a valid option"<<endl;
        }
        cout<<"enter 1 to continue else 0"<<":";
        cin>>flag;
    }
    cout<<"the array is:";
    array.printarray();
    cout<<endl;
    array.resultfinder();
    return 0;
}