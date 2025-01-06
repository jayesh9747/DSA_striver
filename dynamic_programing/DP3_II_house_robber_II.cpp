class Solution {
public:
    int slove(vector<int> &nums, int index, int end) {
        // Base Condition 
        if (index > end) {
            return 0;
        }
        
        int include = nums[index] + slove(nums, index + 2, end);
        int exclude = slove(nums, index + 1, end);

        return max(include, exclude);
    }

    int sloveusingMemo(vector<int> &nums , int index , int end , vector<int>& dp){
        if (index > end) {
            return 0;
        }

        if (dp[index] != -1){
            return dp[index];
        }
        
        int include = nums[index] + sloveusingMemo(nums, index + 2, end,dp);
        int exclude = sloveusingMemo(nums, index + 1, end,dp);

        dp[index] = max(include, exclude);

        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0], nums[1]);  

        vector<int> dp(n , -1); 
        
        // Case 1: Exclude the last house, solve from 0 to n-2
        int case1 = sloveusingMemo(nums, 0, n - 2, dp);
        vector<int> dp1(n , -1); 
        // Case 2: Exclude the first house, solve from 1 to n-1
        int case2 = sloveusingMemo(nums, 1, n - 1,dp1);
        
        // Return the maximum of the two cases
        return max(case1, case2);
    }
};
