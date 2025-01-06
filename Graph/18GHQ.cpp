// path with Minimum efforts 

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater< pair<int, pair<int,int>>> > pq;

        vector<vector<int>> dis(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        pq.push({0,{0,0}});

        dis[0][0] = 0;

        while(!pq.empty()){
            auto frontNode = pq.top();
            pq.pop();

            int frontNodediff = frontNode.first;
            int x = frontNode.second.first;
            int y = frontNode.second.second;

            if(x == heights.size()-1 && y == heights[0].size() -1){
                return dis[x][y];
            }

            int dx[] = {-1 , 0 , 1 , 0};
            int dy[] = {0 ,1,0, -1};

            for(int i = 0 ; i < 4 ; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size()){
                    int currentDiff = abs(heights[newX][newY] - heights[x][y]);

                    int newMax = max(currentDiff , frontNodediff);

                    if (newMax < dis[newX][newY]){
                        dis[newX][newY] = newMax;
                        pq.push({newMax,{newX,newY}});
                    } 
                }
            }
        }
        return 0;
    }
};