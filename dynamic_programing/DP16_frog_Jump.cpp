class Solution {
  public:
    
    int solveUsingRecursion(vector<int>& height, int start, int end) {
        // Base case: if the current index is the last one
        if (start >= end - 1) {
            return 0;
        }
        // Jump to the next step or the step after the next
        int ans1 = solveUsingRecursion(height, start + 1, end) + abs(height[start + 1] - height[start]);
        int ans2 = INT_MAX;
        if (start + 2 < end) {
            ans2 = solveUsingRecursion(height, start + 2, end) + abs(height[start + 2] - height[start]);
        }
        
        return min(ans1, ans2);
    }
    
    int solveUsingMemo(vector<int>& height, int start, int end,vector<int> dp ) {
        if (start >= end - 1) {
            return 0;
        }
        
        if(dp[end] != -1 ){
            return dp[start];
        }

        int ans1 = solveUsingMemo(height, start + 1, end,dp) + abs(height[start + 1] - height[start]);
        int ans2 = INT_MAX;
        if (start + 2 < end) {
            ans2 = solveUsingMemo(height, start + 2, end,dp) + abs(height[start + 2] - height[start]);
        }
        
        dp[start]=  min(ans1, ans2);
        
        return dp[start];
    }
    
    int solveUsingTab(vector<int>& height, int n) {
        // Initialize dp array with 0 for base case and large values for others
        vector<int> dp(n, INT_MAX);
        
        // Base cases
        dp[0] = 0;
        
        // Fill dp array using bottom-up approach
        for (int i = 1; i < n; ++i) {
            // Calculate the energy required for one step jump
            dp[i] = dp[i-1] + abs(height[i] - height[i-1]);
            
            // Calculate the energy required for two steps jump, if applicable
            if (i > 1) {
                dp[i] = min(dp[i], dp[i-2] + abs(height[i] - height[i-2]));
            }
        }

        // Return the minimum energy required to reach the last step
        return dp[n-1];
    }
    
    
    
    
  
    int minimumEnergy(vector<int>& height, int n) {
        
        return solveUsingTab(height, n);
    }
    
};