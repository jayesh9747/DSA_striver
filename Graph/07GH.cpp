#include <bits/stdc++.h>
using namespace std;

// cycle detection in directed graph using the DFS 

bool isCycleDFS(int src ,unordered_map<int, bool>& visited, unordered_map<int , list<int>>& adjList,  unordered_map<int, bool>& DFS_call){
    
    visited[src] = true;
    DFS_call[src] = true;

    for(auto neighbour : adjList[src]){
      if(!visited[neighbour]){
        bool cycledetected = isCycleDFS(neighbour ,visited, adjList,DFS_call);
        if(cycledetected){
          return true;
        }
      }else if(DFS_call[neighbour] == true){
        return true;
      }
    }

    DFS_call[src] = false;

    return false;

}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  // create adjList 

  unordered_map<int , list<int>> adjList;
 
  for(int i = 0 ; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    adjList[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> DFS_call;

  for(int i = 1 ; i <= n  ; i++){

    if(!visited[i]){
      bool cyclefound =  isCycleDFS(i,visited,adjList, DFS_call);
      if(cyclefound){
        return 1;
      }
    }
 
  }

  return 0;
}