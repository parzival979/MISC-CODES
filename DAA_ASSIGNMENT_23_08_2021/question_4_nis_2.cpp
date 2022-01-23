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
            int subarray_sum=0,middleSum=0,x;
            int size=subarray.size();
        for(x=0;x<=size/2;x++)
        {
            for(int i=0;i<size;i++)
            {
              if(i<=x-2)
              {
                  subarray_sum+=(subarray[i]+subarray[size-1-i])*(i+1);
                  subarray_sum-=subarray[size-1-i]*x;
              }
              else{
                  subarray_sum+=subarray[i]*x;
              }
            }
        }
        if(size%2!=0)
        {
           for(int i=0;i<size;i++)
            {
              if(i<=x-2)
              {
                  middleSum+=(subarray[i]+subarray[size-1-i])*(i+1);
                  middleSum-=subarray[size-1-i]*x;
              }
              else{
                  middleSum+=subarray[i]*x;
              }
            } 
        }
          subarray_sum*=2;
          subarray_sum+=middleSum;
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