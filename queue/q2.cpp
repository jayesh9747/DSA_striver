// circular queue

#include <bits/stdc++.h>
using namespace std;


class circularQueue{
    public:

    int * arr;
    int front;
    int rear;
    int size;

    circularQueue(int size){
        arr = new int[size];
        this ->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val){
        //overflow cond 

        if((front == -1 && rear == size-1)||( rear == front -1)){
            cout << "Queue Overflow"<<endl;
        }
        //initial situation

        else if(front== -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }

        //circular condition 
        else if(rear == size -1 && front != 0){
            rear = 0;
            arr[rear] = val;
        }

        //normal condition
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){

        //underflow condition 

        if(front == -1 && rear == -1){
            cout <<"Queue Underflow "<<endl;
        }
        //single element 

        else if (front == rear){
            arr[front] = -1;
            front = -1 ; 
            rear = -1;
        }
        
        //circular condition
        else if(front == size-1){
            arr[front] = -1;
            front = 0;
        }
        //normal condition 
        else{
            arr[front]= -1 ;
            front++;
        }
    }

};

int main(){

}