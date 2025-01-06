class Solution {
  public:
  
    int solveusingRecusion(vector<int>& height, int start,int end, int k){
        if(start >= end-1){
            return 0;
        }
        
        
        int mini = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            if(start+i < end){
                 mini = min(mini , solveusingRecusion(height,start + i , end , k )+ abs(height[start+i] - height[start]));
            }
           
        }
        
        return mini;
        
    }
    
     int solveusingMemo(vector<int>& height, int start,int end, int k,vector<int> dp){
        if(start >= end-1){
            return 0;
        }
        
        if(dp[start] != INT_MAX){
            return dp[start];
        }
       
        for(int i = 1 ; i <= k ; i++){
            if(start+i < end){
                 dp[start] = min(dp[start] , solveusingMemo(height,start + i , end , k, dp )+ abs(height[start+i] - height[start]));
            }
           
        }
        
        return dp[start];
        
    }
    
    
     int solveusingTab(vector<int>& height, int start,int n, int k){

        vector<int> dp(n ,INT_MAX);
        
        
        dp[0] = 0;
        
        
        for(int j = 1 ; j < n ; j++){
            
                 for(int i = 1 ; i <= k ; i++){
                     if(j-i >= 0){
                        dp[j] = min(dp[j] , dp[j-i]+ abs(height[j-i] - height[j]));
                     }
   
                 }
            
        }
        
       
       
        
        return dp[n-1];
        
    }
    
    
    
  
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
    //   vector<int> dp(n+1,INT_MAX);
        return   solveusingTab(height, 0 , n ,k);
    }
};