class Solution {
public:

    // Leet code 733. Flood Fill


    void dfs(int x , int y , int oldcolor, int newcolor,map<pair<int,int> , bool> &visited , vector<vector<int>>& arr ){
        visited[{x,y}] = true;
        arr[x][y] = newcolor;

        int dx[] = {-1, 0 , 1 , 0};
        int dy[] = {0 , 1 , 0 , -1};

        for(int i = 0 ; i < 4 ; i++){
           int newX = x + dx[i];
           int newY = y + dy[i];

            if(newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && !visited[{newX,newY}] && arr[newX][newY] == oldcolor){
                    dfs(newX,newY, oldcolor,newcolor,visited ,arr);
            }
        }
    }



    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        map<pair<int,int> , bool> visited;

        vector<vector<int>> ans = image;
        dfs(sr,sc,oldcolor,color,visited,ans);

        return ans;
    }
};