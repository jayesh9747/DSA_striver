// Partition Equal Subset Sum


class Solution {
public:

     bool solveUsingRec(vector<int>& num, int t, int index) {
        if (t == 0) {
            return true;
        }
        if (index >= num.size() || t < 0) {
            return false;
        }

        bool include = solveUsingRec(num, t - num[index], index + 1);
        bool exclude = solveUsingRec(num, t, index + 1);

        return include || exclude;
    }

    bool solveusingMemo(vector<int>& num, int t, int index , vector<vector<int>>&dp){
        if (t == 0) {
            return true;
        }
        if (index >= num.size() || t < 0) {
            return false;
        }

        if(dp[index][t] != -1){
            return dp[index][t];
        }

        bool include = solveusingMemo(num, t - num[index], index + 1,dp);
        bool exclude = solveusingMemo(num, t, index + 1,dp);


        dp[index][t] = include || exclude;

        return dp[index][t];
    }


    bool solveusingTab(vector<int>& num,int target){
        
        int n = num.size();
        vector<vector<int>>dp(target+1, vector<int>(n+1,0));

        

        for(int t = 0 ; t <= target ; t++){
            for(int index = n-1 ; index >= 0 ; index--){

                if(t > target){
                    continue;
                }

                bool include = dp[t - num[index]][index + 1];
                bool exclude = dp[t][index + 1];
                dp[t][index] = include || exclude;
            }
        }

        return dp[target][0];

    }



    bool canPartition(vector<int>& nums) {

        int sum =0 ;

        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }

        if(sum %2 != 0) return false;

        int t = sum/2;

        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(t+1,-1));

        // bool ans =  solveUsingRec(nums, t, 0);

        // bool ans =  solveusingMemo(nums, t, 0, dp);

        bool ans =  solveusingTab(nums, t);

        return ans;
        
    }
};