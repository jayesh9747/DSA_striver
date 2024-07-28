class Solution {
public:

    int solveusingRec(string a , string b , int i , int j){
        if(i >= a.size() || j >= b.size()){
            return 0;
        }
        // first char macth
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1+ solveusingRec(a , b, i+1 , j+1);
        }else {
            ans = 0+ max(solveusingRec(a , b, i , j+1), 
                        solveusingRec(a , b, i+1, j));
        }
        return ans;

    }

     int solveusingMem(string& a , string& b , int i , int j, vector<vector<int>> &dp){
        if(i >= a.size() || j >= b.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // first char macth
        int ans = 0;
        if(a[i] == b[j]){
            dp[i][j] = 1+ solveusingMem(a , b, i+1 , j+1,dp);
        }else {
            dp[i][j] = 0+ max(solveusingMem(a , b, i , j+1,dp), 
                        solveusingMem(a , b, i+1, j,dp));
        }
        return dp[i][j];

    }

    int solveusingTab(string& a , string& b ){
        
        vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1,0));

        for(int i_index = a.size()-1 ; i_index >= 0 ; i_index--){
            for(int j_index = b.size()-1 ; j_index >= 0 ; j_index--){
                if(a[i_index] == b[j_index]){
                        dp[i_index][j_index] = 1+ dp[i_index+1][j_index+1];
                }else {
                        dp[i_index][j_index] = 0+ max(dp[i_index][j_index+1],dp[i_index+1][j_index]);
                    }
            }
        }
        return dp[0][0];
    }

    // hame bas to vector ki hi jrurat hai apna ans lane ke liye 
    int solveusingTabSO(string& a , string& b ){

        vector<int> curr(a.size()+1,0);
        vector<int> next(a.size()+1,0);
        for(int j_index = b.size()-1 ; j_index >= 0 ; j_index--){
            for(int i_index = a.size()-1 ; i_index >= 0 ; i_index--){
                if(a[i_index] == b[j_index]){
                        curr[i_index] = 1+ next[i_index+1];
                }else {
                        curr[i_index] = 0+ max(next[i_index],curr[i_index+1]);
                    }
            }
            //shifting
            next = curr;
        }
        return next[0];
    }


    int longestCommonSubsequence(string text1, string text2) {
       
        int i = 0 ; 
        int j = 0 ;
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));

        int ans = solveusingTabSO(text1 , text2);
        return ans;
    }
};