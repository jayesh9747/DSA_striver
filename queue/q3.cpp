#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    stack<int> st;

    // Reversing the queue using a stack
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st.push(t);
    }

    // Printing the reversed queue
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        cout << top << endl; // Changed st.top() to top
    
    }

    return 0;
}
