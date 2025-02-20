class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& v) {
        vector <int> ans;
        map<int,int> mp;
        stack<int> st;
        int n = v.size();
        for (int i = n-1 ; i>=0 ; i--){
            // there are three condtion 
            if(st.size()==0){
                ans.push_back(-1);
            }else if(st.top() > v[i] && st.size() > 0){
                    int t = st.top();
                    ans.push_back(t);
            }else if(st.size() > 0 && st.top() <= v[i] ){
                while(st.size() > 0 && st.top() <= v[i] ){
                    st.pop();
                }
                if(st.size()==0){
                    ans.push_back(-1);
                }else{
                    int t = st.top();
                    ans.push_back(t);
                }
            }
           st.push(v[i]);
        }
    reverse(ans.begin(),ans.end());
    for(int i =0 ; i< ans.size(); i++){
        mp[v[i]] = ans[i];
    }
    vector<int> t ;
    for(auto it : nums1){
        t.push_back(mp[it]);
    }
        return t;
    }
};