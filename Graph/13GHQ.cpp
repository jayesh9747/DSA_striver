class Solution {
public:

    // leet code - 547 - Number of provinces

    // no of component find karne the 

    void dfs(int src ,unordered_map<int, bool> &visited,vector<vector<int>>& isConnected){
        visited[src] = true;

        for(int i = 0 ; i < isConnected[0].size() ; i++){
                if(isConnected[src][i] == 1 && !visited[i]){
                    dfs(i , visited, isConnected);
                }
        }
        
    }


    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, bool> visited;
        int n = isConnected.size();
        int count = 0;

        for(int i = 0 ; i < n ; i++){

            if(!visited[i]){
                dfs(i,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};