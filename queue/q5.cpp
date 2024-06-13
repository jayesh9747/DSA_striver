//  reverse first K element of Queue 

#include<bits/stdc++.h>
using namespace std;



void ReverseFirstKElement(queue<int> &q,int k){
        int count = 0;
        int n = q.size();

        if(k< 0 && k > n) return;

        if(k == 0){
            return;
        }

        stack<int> st;

        while(!q.empty()){
            int t = q.front();
            q.pop();
            count++;
            st.push(t);
            
            if(count == k){
                break;
            }
        }

        while(!st.empty()){
            int top = st.top();
            st.pop();
            q.push(top);
        }

        if(k == n){
            return;
        }

        count = 0 ;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            q.push(t);
            count++;
            if(count == n-k){
                break;
            }
        }

}



int main(){


    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    ReverseFirstKElement(q,5);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

}