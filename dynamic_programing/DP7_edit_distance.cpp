class Solution {
public:

    int solveusingRec(string a , string b, int i , int j){

        // base case
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }

        int ans = 0;
        // character matching
        if(a[i] == b[j]){
            ans = 0 + solveusingRec(a,b ,i+1, j+1);
        }else{
            int replace = 1 + solveusingRec(a,b ,i+1, j+1);
            int remove = 1 + solveusingRec(a,b ,i+1, j);
            int insert = 1 +  solveusingRec(a,b ,i, j+1);
            ans = min(insert , min(remove, replace));
        }
        return ans;

    }

    int solvesusingMemo(string& a , string& b, int i , int j,vector<vector<int>>& dp){
         // base case
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        // character matching
        if(a[i] == b[j]){
            dp[i][j] = 0 + solvesusingMemo(a,b ,i+1, j+1,dp);
        }else{
            int replace = 1 + solvesusingMemo(a,b ,i+1, j+1,dp);
            int remove = 1 + solvesusingMemo(a,b ,i+1, j,dp);
            int insert = 1 +  solvesusingMemo(a,b ,i, j+1,dp);
            dp[i][j] = min(insert , min(remove, replace));
        }
        return dp[i][j];
    }

    int solveusingTab(string a , string b){
        vector<vector<int>> dp(a.length()+1 ,vector<int>(b.length()+1,0));

        for(int i = 0 ; i < b.length(); i++){
            dp[a.length()][i] = b.length() - i;
        }

        for(int i = 0 ; i < a.length(); i++){
            dp[i][b.length()] = a.length() - i;
        }

        for( int i = a.size()-1 ; i >= 0 ; i--){
            for(int j = b.size()-1 ; j >= 0 ; j--){
                    if(a[i] == b[j]){
                        dp[i][j] = 0 + dp[i+1][j+1];
                    }else{
                        int replace = 1 + dp[i+1][j+1];
                        int remove = 1 + dp[i+1][j];
                        int insert = 1 +  dp[i][j+1];
                        dp[i][j] = min(insert , min(remove, replace));
                    }
            }
        }

        return dp[0][0];

    }


    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0 ;

        // vector<vector<int>> dp(word1.length()+1 ,vector<int>(word2.length()+1,-1));

        // int ans = solveusingRec(word1,word2, i , j);
        // int ans = solvesusingMemo(word1,word2, i , j,dp);
        int ans = solveusingTab(word1,word2);
        return ans;
    }
};