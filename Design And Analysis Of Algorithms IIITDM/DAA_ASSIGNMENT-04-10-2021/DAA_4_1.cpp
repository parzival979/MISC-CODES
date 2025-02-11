#include<iostream>
#include<vector>
using namespace std;
class sorting
{
    private:
        vector<int>sortingArray;
    public:
        void push(int data)
        {
            sortingArray.push_back(data);
        }
        void display()
        {
            for(int i=0;i<sortingArray.size();i++)
            {
                cout<<sortingArray[i]<<" ";
            }
            cout<<"\n";
        }
        void swap(int i,int j)
        {
            int temp=sortingArray[i];
            sortingArray[i]=sortingArray[j];
            sortingArray[j]=temp;
        }
        void bubbleSort()
        {
            for(int i=0;i<sortingArray.size()-1;i++)
            {
                for(int j=i+1;j<sortingArray.size();j++)
                {
                    if(sortingArray[i]>sortingArray[j])
                    {
                        swap(i,j);
                    }
                }
            }
        }
        void selectionSort()
        {
            int min,min_index,temp;
            for(int i=0;i<sortingArray.size();i++)
            {
                min=sortingArray[i]; min_index=i;
                for(int j=i;j<sortingArray.size();j++)
                {
                    if(min>sortingArray[j])
                    {
                        min=sortingArray[j];
                        min_index=j;
                    }
                }
                swap(i,min_index);
            }
        }
        void insertionSort()
        {
            for(int i=0;i<sortingArray.size();i++)
            {
                if(i>0)
                {
                    if(sortingArray[i]<sortingArray[i-1])
                    {
                        swap(i,i-1);
                        for(int j=i-1;(j>0)&&(sortingArray[j]<sortingArray[j-1]);j--)
                        {
                            swap(j,j-1);
                        }
                    }
                }
            }
        }
        void merge(int p, int q, int r)
        {
            int n1=q-p+1;
            int n2=r-q;
            int first[n1],second[n2];
            for(int i=0;i<n1;i++)
            {
                first[i]=sortingArray[p+i];
            }
            for(int i=0;i<n2;i++)
            {
                second[i]=sortingArray[q+1+i];
            }

            int i=0,j=0,k=p;
            while(i<n1&&j<n2)
            {
                if(first[i]<=second[j])
                {
                    sortingArray[k]=first[i];
                    i++;
                }
                else
                {
                    sortingArray[k]=second[j];
                    j++;
                }
                k++;
            }
            while(i<n1)
            {
                sortingArray[k]=first[i];
                i++;
                k++;
            }
            while(j<n2)
            {
                sortingArray[k]=second[j];
                j++;
                k++;
            }
        }
        void mergeSort(int low,int high)
        {
            if(low<high)
            {
                int mid=low+(high-low)/2;
                mergeSort(low,mid);
                mergeSort(mid+1,high);
                merge(low,mid,high);
            }
        }
        void mergeCall()
        {
            int low=0; int high=sortingArray.size()-1;
            mergeSort(low,high);
        }
        void heapify(int n,int i)
        {
            int root=i;
            int left=2*i+1;
            int right=2*i+2;
            if(left<n && sortingArray[left]>sortingArray[root])
            {
                root=left;
            }


            if(right<n && sortingArray[right]>sortingArray[root])
            {
                root=right;
            }


            if(root!=i)
            {
                swap(root,i);
                heapify(n,root);
            }
        }
        void heapSort()
        {
            int n=sortingArray.size();
            for(int i=n/2-1;i>=0;i--)
            {
                heapify(n,i);
            }
            for(int i=n-1;i>0;i--)
            {
                swap(0,i);
                heapify(i,0);
            }
        }

};
int main()
{
    sorting array;
    int size,data;
    cout<<"Enter the size of the array:";
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter the element:";
        cin>>data;
        array.push(data);
    }
    cout<<"The array is:";
    array.display();
    array.bubbleSort();
    cout<<"Array after bubble sorting is:";
    array.display();
    array.selectionSort();
    cout<<"Array after selection sorting is:";
    array.display();
    array.insertionSort();
    cout<<"Array after insertion sorting is:";
    array.display();
    array.heapSort();
    cout<<"Array after heap sorting is:";
    array.display();
    array.mergeCall();
    cout<<"Array after merge sorting is:";
    array.display();
    return 0;
}