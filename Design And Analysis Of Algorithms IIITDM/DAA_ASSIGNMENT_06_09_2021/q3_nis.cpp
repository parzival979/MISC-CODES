#include<iostream>
#include<vector>
using namespace std;
class searchArray_program
{
    vector<int>searchArray;
    public:
        void arrayAdder(int data)
        {
            searchArray.push_back(data);
        }
        void arrayPrinter()
        {
            cout<<"the array elements are:";
            for(int i=0;i<searchArray.size();i++)
            {
                cout<<searchArray[i]<<" ";
            }
            cout<<endl;
        }
        void arraySorter()
        {
            for(int i=0;i<searchArray.size()-1;i++)
            {
                for(int j=i+1;j<searchArray.size();j++)
                {
                    if(searchArray[i]>searchArray[j])
                    {
                        int temp=searchArray[i];
                        searchArray[i]=searchArray[j];
                        searchArray[j]=temp;
                    }
                }
            }
        }
        int recursiveTernary(vector<int>searchArray,int low,int high,int target)
        {
                int mid1=low+(high-low)/3;
                int mid2=high-(high-low)/3;
                if(low<=high)
                {
                    if(target==searchArray[mid1])
                    { return mid1; }
                    else if (target==searchArray[mid2])
                    { return mid2; }
        
                    if(target<searchArray[mid1])
                    {
                        return recursiveTernary(searchArray,low,mid1-1,target);
                    }
                    else if(target>searchArray[mid2])
                    {
                        return recursiveTernary(searchArray,mid2+1,high,target);
                    }
                    else
                    {
                        return recursiveTernary(searchArray,mid1+1,mid2-1,target);
                    }
                }
    
                return -1;
        }
        int iterativeTernary(vector<int>searchArray,int low, int high,int target)
        {
            int mid1=low+(high-low)/3;
            int mid2=high-(high-low)/3;
            while(low<=high)
            {
                 mid1=low+(high-low)/3;
                 mid2=high-(high-low)/3;
                if(searchArray[mid1]==target)
                {return mid1;}
                else if(searchArray[mid2]==target)
                { return mid2;}

                if(target<searchArray[mid1])
                {
                    high=mid1-1;
                }
                else if(target>searchArray[mid2])
                {
                    low=mid1+1;
                }
                else
                {
                    low=mid1+1;
                    high=mid2-1;
                }
            }
            return -1;
        }
        int recursiveBinary(vector<int>searchArray,int low, int high,int target)
        {
            int mid=(low+high)/2;
            if( low<=high)
            {
            if(searchArray[mid]==target)
            {
                return mid;
            }
            else if(searchArray[mid]>target)
            {
                return recursiveBinary(searchArray,low,mid-1,target);
            } 
            else
            {
                return recursiveBinary(searchArray,mid+1,high,target);
            }
            }

            return -1;  
        }
        int iterativeBinary(vector<int>searchArray,int low,int high,int target)
        {
            int mid=(low+high)/2;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(searchArray[mid]==target)
                {
                    return mid;
                }
                else if(searchArray[mid]>target)
                {
                    high=mid-1;
                } 
                else
                {
                    low=mid+1;
                }
            }
            return -1;
        }
        void functionCalls(int target)
        {
            int element=recursiveBinary(searchArray,0,searchArray.size()-1,target);
            cout<<"RecursiveBinarySearch:";
            if(element!=-1)
            {
                cout<<"The element found at index "<<element<<endl;
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }

            element=iterativeBinary(searchArray,0,searchArray.size()-1,target);
            cout<<"IterativeBinarySearch:";
            if(element!=-1)
            {
                cout<<"The element found at index "<<element<<endl;
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }

            element=recursiveTernary(searchArray,0,searchArray.size()-1,target);
            cout<<"RecursiveTernarySearch:";
            if(element!=-1)
            {
                cout<<"The element found at index "<<element<<endl;
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }

            element=iterativeTernary(searchArray,0,searchArray.size()-1,target);
            cout<<"IterativeTernarySearch:";
            if(element!=-1)
            {
                cout<<"The element found at index "<<element<<endl;
            }
            else
            {
                cout<<"Element is not found"<<endl;
            }
        }

};
int main()
{
    int size,data,target;
    searchArray_program array; 
    cout<<"Enter size of array:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter array element:";
        cin>>data;
        array.arrayAdder(data);
    }
    cout<<"After sorting ";
    array.arraySorter();
    array.arrayPrinter();
    cout<<"Enter the element you wanted to search for:";
    cin>>target;
    array.functionCalls(target);
    return 0;
}