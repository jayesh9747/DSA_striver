// Que
// find middle element of Stack 


#include<bits/stdc++.h>
using namespace std;

void getMiddleOfStack(stack<int> &st,int ind,int& ans){

    if(st.size()==ind ){
        ans = st.top();
        return;
    }

    int temp = st.top();
    st.pop();
    getMiddleOfStack(st,ind,ans);
    st.push(temp);
}


int main(){

 stack<int> st;

 st.push(10);
 st.push(20);
 st.push(30);
 st.push(40);
 st.push(50);
 st.push(60);
 st.push(70);

    int ind = (st.size()/2)+1;
    int ans=0;
    getMiddleOfStack(st,ind,ans);


    cout<<"Mid of Stack"<<ans<<endl;


    //check 
    while (!st.empty())
    {
        cout<< st.top()<< " ";
        st.pop();
    }
    

}