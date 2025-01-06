class Solution {
public:

    int slove(vector<int> & nums , int index){

        // Base Condition 
        if (index > nums.size()-1){
            return 0;
        }
        int maxi = INT_MIN;

        int include = nums[index] + slove(nums, index + 2);
        int exclude =  slove(nums,index +1);

        maxi = max(include, exclude);

        return maxi ;

    }

    //  Memo

    int solvememo(vector<int> & nums , int index, vector<int> & dp){
          // Base Condtion 
        if (index > nums.size()-1){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }


        int maxi = INT_MIN;

        int include = nums[index] + solvememo(nums, index + 2,dp);
        int exclude =  solvememo(nums,index +1,dp);

        dp[index] = max(include, exclude);

        return dp[index];

    }

    int sloveusingTab(vector<int> & nums, int n ){

        vector<int> dp(n+1 ,INT_MIN);

        dp[n-1] = nums[n-1] ; 
     
        for(int i = n-2 ; i >= 0 ; i-- ){
        int tempans = 0;
        if(i <  n -2){
            tempans = dp[i+2];
        }
        int include = nums[i] + tempans;
        int exclude =  dp[i+1];
        dp[i] = max(include, exclude);
        }

        return dp[0];
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1 , -1) ;
        // return solvememo(nums,0, dp);
        return sloveusingTab(nums , n);
    }
};