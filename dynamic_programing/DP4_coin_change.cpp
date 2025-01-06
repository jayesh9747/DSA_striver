class Solution {
public:

    int sloveusingRec(vector<int>& coins, int amount){
        // base case 

        if(amount == 0) {
            return 0;
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size(); i++){

            int recans = 0;
            // idhar hi negative wali condition handle ki gai hai 
            if(amount - coins[i] >=0){
                recans =  sloveusingRec(coins , amount - coins[i]) ;
                if(recans != INT_MAX){
                int inculde  = recans+ 1; 
                ans = min(inculde, ans);
                }  
            }    
        }

       return ans;
    }

    int solveusingMemo(vector<int>& coins, int amount ,vector<int> dp){

        if(amount == 0) {
            return 0;
        }

        if(dp[amount] != -1){
            return dp[amount];
        }

        int ans = INT_MAX;
        for(int i = 0 ; i < coins.size(); i++){

            if(amount - coins[i] >=0){
              int  recans =  solveusingMemo(coins, amount - coins[i], dp);
                if(recans != INT_MAX){
                int inculde  = recans+ 1; 
                ans = min(inculde, ans);
                }  
            }    
        }
        dp[amount] = ans;
       return dp[amount];
    }

    int solveusingTab(vector<int>& coins, int amount ){
        
        vector<int> dp(amount+1 , -1); 
        
        dp[0] = 0;

        
        for( int j = 1 ; j <= amount ; j++){
            int ans = INT_MAX;
            for(int i = 0 ; i < coins.size(); i++){           
                if(j - coins[i] >=0){
               int  recans =  dp[j - coins[i]];
                if(recans != INT_MAX){
                int inculde  = recans+ 1; 
                ans = min(inculde, ans);
                }  
                }
            }
            dp[j] = ans;
        }
        
        return dp[amount];
       
    }

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount+1 , -1); 

        int ans =  solveusingTab(coins, amount);
        
        if (ans == INT_MAX){
            return -1; 
        }else {
            return ans;
        }
    }
};