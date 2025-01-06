class Solution {
public:

    bool dfs(unordered_map<int , list<int>>& adjList, vector<int>& color , int curr , int currColor){
        color[curr] = currColor;

        for(auto nbr : adjList[curr]){
            if(color[nbr] == currColor){
                return false;
            }

            if(color[nbr] == -1){
                int nodecolor = 1 - currColor;
                if(dfs(adjList , color , nbr , nodecolor) == false){
                    return false;
                }
            }
        }

        return true;
    }


    bool Bfs(unordered_map<int,list<int>>& adjList , vector<int> &color , int start , int startcolor){
            queue<pair<int, int>> q;

            color[start] = startcolor;
            q.push({start , startcolor});

            while(!q.empty()){
                auto top = q.front();
                q.pop();

                int node = top.first;
                int nodecolor = top.second;

                for(auto nbr : adjList[node]){
                    if(color[nbr] == nodecolor){
                        return false;
                    }
                    if(color[nbr] == -1){
                        color[nbr] = 1-nodecolor;
                        q.push({nbr , 1- nodecolor});
                    }
                }
            } 

        return true;   
    }


    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int ,list<int>> adjList;

        for(int i= 0 ; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                adjList[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(graph.size() , -1);


        for(int i = 0 ; i < graph.size(); i++){
                if(color[i] == -1){
                    if(Bfs(adjList,color,i,1) == false){
                        return false;
                    }
                }
        }

        return true;
    }
};