// reverse the stack 

#include <bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    InsertAtBottom(st, val);
    st.push(temp);
}

void reverseStack(stack<int>& st){

        //base case
        if(st.empty()){
            return;
        }

        int t = st.top();
        st.pop();

        //reverse the stack 
        reverseStack(st);
        
        InsertAtBottom(st,t);  

}



int main(){

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    reverseStack(st);


    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}