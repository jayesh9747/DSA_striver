
// cycle detection  

//  1. directed graph using BFS 
//  2. directed graph using DFS  
//  3. undirected graph using BFS 
//  4. undirected graph using DFS 

#include <bits/stdc++.h>
using namespace std;

// 1.  undirected graph using BFS 
void createAdjList(vector<vector<int>>& edges, unordered_map<int,list<int>> &AdjList ){
    for(int i = 0 ; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }
}

bool bfs(int src,unordered_map<int,bool>&visited, unordered_map<int, int>& parent, unordered_map<int,list<int>> &AdjList){

    queue<int> q;
    
    q.push(src);
    parent[src] = -1 ;
    visited[src] = true;
    

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : AdjList[frontNode]){

            if((visited[neighbour] == true) && (neighbour != parent[frontNode])){
                return  true;
            }

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }

           
        }

    }


    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

    unordered_map<int,list<int>> AdjList;

    createAdjList(edges,AdjList);

    unordered_map<int,bool> visited;
    unordered_map<int, int> parenet;

    for(int i = 0 ; i < n; i++){
        if(!visited[i]){
           bool ans = bfs(i, visited, parenet,AdjList );

           if(ans == true){
               return "Yes";
           }
        }
    }

    return "No";

}
