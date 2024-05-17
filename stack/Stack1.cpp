#include<bits/stdc++.h>
using namespace std;

int main(){

    //creation 
    stack<int> st;

    //insertion 
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // 40 30 20 10 

    //remove 

    st.pop();

    //check element on the top of stack 

    cout << "element on the top of stack " << st.top() << endl;

    //size 

    int size = st.size();

    cout<< "size of the stack is "<< size << endl;

    if(st.empty()){
        cout<< "Stack is empty"<< endl;
    }else{
        cout << "Stack is not empty"<<endl; 
    }

    //print the stack 

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while(!s.empty()){
        cout<< s.top()<<" ";
        s.pop();
    }

}