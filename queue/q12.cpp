// stack using queue

// 2 methods

// 1. using two Queue
// 2. using only one queue



#include<bits/stdc++.h>
using namespace std;


// using 2 Queues 
class MyStack {
public:
    queue<int> q1 ; 
    queue<int> q2;        
    MyStack() {
   
    }
    
    void push(int x) {
        q2.push(x);

        // q1 se element nikal ke q2 mai dal diya
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // q2 se sare element nikal ke q1 mai dal denge
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    
    int pop() {

        int top = q1.front();
        q1.pop();
        return top;
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


// using Single Queue 

class MyStack {
public:
    queue<int> q1;    
    MyStack() {
   
    }
    
    void push(int x) {
        
        q1.push(x);

        int size = q1.size();

        for(int i = 0 ; i < size-1 ; i++){
            int top = q1.front();
            q1.pop();
            q1.push(top);
        }

    }
    
    int pop() {

        int top = q1.front();
        q1.pop();
        return top;
        
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main()
{
}