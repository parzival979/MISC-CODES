#include<iostream>
using namespace std;
class array_stack
{
        private:
            int *arr;
            int size;
            int top1,top2;
        public:
            array_stack(int size_array)
            {
                size=size_array;
                arr=new int[size];
                top1=-1; top2=size;
            }
            void push1(int data)
            {
                if(top1==top2-1)
                {
                    cout<<"No space to insert an element"<<endl;
                }
                else
                {
                    top1++;
                    arr[top1]=data;
                }
            }
            void push2(int data)
            {
                if(top1==top2-1)
                {
                    cout<<"No space to insert an element"<<endl;
                }
                else
                {
                    top2--;
                    arr[top2]=data;
                }
            }
            int pop1()
            {
                if(top1==-1)
                {
                    cout<<"Stack is empty"<<endl;
                    return -1;
                }
                else
                {
                    cout<<"Popped element is:";
                    int temp=arr[top1];
                    top1--;
                    return temp;
                }
            }
            int pop2()
            {
                if(top2==size)
                {
                    cout<<"Stack is empty"<<endl;
                    return -1;
                }
                else
                {
                    cout<<"Popped element is:";
                    int temp=arr[top2];
                    top2++;
                    return temp;
                }
            }

};
int main()
{
    int size_array;
    cout<<"Enter size of array:";
    cin>>size_array;
    array_stack array(size_array);
    int choice,data;
    while(1)
    {
        cout<<"1.push into stack1"<<endl;
        cout<<"2.Push into stack2"<<endl;
        cout<<"3.Pop from stack1"<<endl;
        cout<<"4.Pop from stack2"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element to insert in stack 1:";
                cin>>data;
                array.push1(data);
                break;
            case 2:
                cout<<"Enter element to insert in stack 2:";
                cin>>data;
                array.push2(data);
                break;
            case 3:
               data=array.pop1();
               if(data!=-1)
               {
                   cout<<data<<endl;
               }
               break;
            case 4:
                data=array.pop2();
               if(data!=-1)
               {
                   cout<<data<<endl;
               }
                break;
            case 5:
                exit(1);
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }

    
    return 0;
}