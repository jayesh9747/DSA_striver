// Queue using Stack 


// 2 Methods 

// 1. push operation O(n)
// 2. pop operation O(n)


#include<bits/stdc++.h>
using namespace std;


// method 1 
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {

        if(s1.empty()){
            s1.push(x);
        }else{
            while(!s1.empty()){
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
            s1.push(x);
            while(!s2.empty()){
                int top = s2.top();
                s2.pop();
                s1.push(top);
            }
        }
        
    }
    
    int pop() {
        if(s1.empty()){
            return -1;
        }else{
            int top = s1.top();
            s1.pop();
            return top;
        }
    }
    
    int peek() {

        return s1.top();
        
    }
    
    bool empty() {
        return s1.empty();
    }
};





int main(){

}