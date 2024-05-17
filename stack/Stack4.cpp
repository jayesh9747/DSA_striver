#include<bits/stdc++.h>
using namespace std;


int main(){

    stack<char> st;

    string s;
    cin >> s;

    // cout << s << endl;

    for(int i = 0 ; i < s.size(); i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        cout<<st.top();
            st.pop();
    }
    cout<< endl;
}