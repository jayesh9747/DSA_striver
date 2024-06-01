//prev Smaller Element 


#include<bits/stdc++.h>
using namespace std;


void PrevSmallerElement(vector<int>v,vector<int>&ans){
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

    vector <int> temp = {1,1};

    vector<int>ans;

    PrevSmallerElement(temp,ans);

    for(int i = 0 ; i < ans.size(); i++){
        cout<< ans[i]<<" ";
    }

}

