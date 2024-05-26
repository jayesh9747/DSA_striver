// insert at bottom

// here we use the recursion

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

int main()
{

    stack<int> st;

    int t = 100;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    InsertAtBottom(st, t);

    // check
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}