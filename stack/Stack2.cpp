#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int top;  // index
    int *arr; // pointer for the array
    int size; // size of stack

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // function

    void push(int data)
    {
        if (top <= size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if(top > -1 ){
            top--;
        }else{
            cout<<"Stack Underflow"<<endl; 
        }
    }

    int getTop()
    {   
        if(top == -1){
            cout<<"There is not element in stack"<<endl;
            return -1;
        }
        return arr[top]; 
    }

    bool isempty()
    {
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }

    int Size()
    {
        return top+1;
    }
};

int main()
{

    Stack s(20);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<"Top of the element "<<s.getTop()<<endl;

    s.pop();
    cout<<"Top of the element "<<s.getTop()<<endl;
    s.pop();
    cout<<"Top of the element "<<s.getTop()<<endl;
    s.pop();
    cout<<"Top of the element "<<s.getTop()<<endl;
    s.pop();
    

    cout<< s.isempty() << endl;


}