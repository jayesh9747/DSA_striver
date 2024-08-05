class Solution {
public:

    int sloveusingRec(vector<int>& num , int prev , int curr){

        // base case 

        if(curr >= num.size()){
            return 0;
        }

        int include = 0;
        if(prev == -1 || num[curr] > num[prev]){
            include = 1 + sloveusingRec(num , curr , curr+1);
        }
        int exclude = 0 + sloveusingRec(num , prev , curr+1);
        

        return max(include, exclude);
    }

    int solveusingMem(vector<int>& num , int prev , int curr,vector<vector<int>>& dp ){
        if(curr >= num.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1 ){
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || num[curr] > num[prev]){
            include = 1 + solveusingMem(num , curr , curr+1,dp);
        }
        int exclude = 0 + solveusingMem(num , prev , curr+1, dp);
        
        dp[curr][prev+1] = max(include, exclude);

        return dp[curr][prev+1] ;
    }

    int solveusingTab(vector<int>& nums){
        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , 0));

        for(int i = nums.size()-1; i >=0  ; i--){ // curr 
            for(int j = i-1 ; j >=-1 ;j--){ // prev
                int include = 0;
                if(j == -1 || nums[i] > nums[j]){
                     include = 1 + dp[i+1][i+1];
                }
                int exclude = 0 + dp[i+1][j+1];
        
                dp[i][j+1] = max(include, exclude);
            }
        }

        return dp[0][0];
    }

    int solveusingTabSO(vector<int>& nums){
        // vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , 0));
        int n  = nums.size() ;
        vector<int> currRow(n+1 , 0);
        vector<int> nextRow(n+1 , 0);

        for(int i = nums.size()-1; i >=0  ; i--){ // curr 
            for(int j = i-1 ; j >=-1 ;j--){ // prev
                int include = 0;
                if(j == -1 || nums[i] > nums[j]){
                     include = 1 + nextRow[i+1];
                }
                int exclude = 0 + nextRow[j+1];
        
                currRow[j+1] = max(include, exclude);
            }
            //shifting
            nextRow = currRow;
        }

        return nextRow[0];
    }

    // agar ans hamara sorted ho tab hame binary search lagana chhahiye 

    int solveusingBS(vector<int>& nums){
        vector<int> ans ; 

        ans.push_back(nums[0]);

        for(int i = 1 ; i < nums.size(); i++){
            // sabse bada number include 
            if(nums[i] > ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    

    int lengthOfLIS(vector<int>& nums) {

        int prev = -1 ; 
        int curr = 0; 


        vector<vector<int>> dp(nums.size()+1 , vector<int>(nums.size()+1 , -1));
        // int ans = sloveusingRec(nums, prev , curr);
        int ans = solveusingBS(nums);

        return ans;
        
    }
};