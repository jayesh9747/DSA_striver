//prev Smaller Element 


#include<bits/stdc++.h>
using namespace std;


void NextSmallerElement(vector<int>v,vector<int>&ans){
    stack <int> st;
    st.push(-1);
    for(int i = 0 ; i < v.size(); i++){
        int curr = v[i];

        while(curr <= st.top()){
            st.pop();
        }
        ans.push_back(st.top());

        st.push(curr);
    }
  

}



int main(){

    vector <int> temp = {2,3,4,1};

    vector<int>ans;

    NextSmallerElement(temp,ans);

    for(int i = 0 ; i < ans.size(); i++){
        cout<< ans[i]<<" ";
    }

}

