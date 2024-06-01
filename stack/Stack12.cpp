// Next Min element

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    vector<int> v;
    st.push(-1);

    int a[4] = {2, 1, 4, 3};

    for (int i = 3; i >= 0; i--)
    {

        int t = a[i];

        while (t <= st.top())
        {
            st.pop();
        }

        v.push_back(st.top());

        st.push(a[i]);
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
