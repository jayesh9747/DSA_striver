class Solution {
public:

    int solveusingRec(int n){
        if(n == 0){
            return 1;
        }

        int take_1 = 0, take_2 = 0;
        if(n >= 1)
        take_1 = take_1 + solveusingRec(n-1);

        if(n >= 2)
        take_2 = take_2 + solveusingRec(n-2);

        return take_1+ take_2;

    }

    int solveusingMem(int n , vector<int>& dp){
        if(n == 0){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int take_1 = 0, take_2 = 0;
        if(n >= 1)
        take_1 = take_1 + solveusingMem(n-1,dp);

        if(n >= 2)
        take_2 = take_2 + solveusingMem(n-2,dp);

        return dp[n] = take_1+ take_2;

    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solveusingMem(n ,dp);
    }   
};