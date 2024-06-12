#include <bits/stdc++.h>
using namespace std;

class Queue
{

public:
    int *arr;
    int front;
    int size;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // check full
        if (rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            if (rear == -1 && front == -1)
            {
                front++;
                rear++;
                arr[rear] = val;
            }
            else
            {
                rear++;
                arr[rear] = val;
            }
        }
    }

    void pop(){
        if(front == -1 && rear == -1){
           cout << " Queue Underflow"<<endl;
           return; 
        }else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1 ;
        }else{
            arr[front]= -1;
            front++;
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }else{
            return false;
        }
    }

    bool getsize(){
        //  bhul jate hai 
        if(front == -1  && rear == -1){
            return 0;
        }else{
        return rear-front+1;
        }
    }

    int getFront(){
        if(front == -1){
            cout << "No element in queue,can not give front element"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(rear == -1){
            cout << "No element in queue,can not give front element"<<endl;
            return -1;
        }
        return arr[rear];
    }


    void print(){
       cout <<"printing the queue"<<endl;

       for(int i = 0; i < size ; i++){
        cout << arr[i]<< " ";
       }
       cout <<endl; 
    }

};

int main()
{
}