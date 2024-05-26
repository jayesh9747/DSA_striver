//sort the Stack

#include<bits/stdc++.h>
using namespace std;


void InsertInSortedPostion(stack<int> &St ,int top){

    if(St.empty()){
        St.push(top);
        return;
    }
    if(St.top()>= top){
        St.push(top);
        return;
    }

    int t = St.top();

    St.pop();

    InsertInSortedPostion(St,top);

    St.push(t);
   
}


void SortTheStack(stack<int> &St){

    //base condition
    if(St.empty()){
        return;
    }

    int topEle = St.top();

    St.pop();

    SortTheStack(St);

    InsertInSortedPostion(St,topEle);
    
}







int main(){

stack<int> st;

    st.push(10);
    st.push(30);
    st.push(20);
    st.push(60);
    st.push(50);
    st.push(40);

    SortTheStack(st);


    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }


}