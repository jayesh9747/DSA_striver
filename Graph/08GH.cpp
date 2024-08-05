#include <bits/stdc++.h> 
using namespace std;


// topology sort using dfs 

void topological_sort(int src ,unordered_map<int, list<int> >& adjList,vector< bool>& visited, vector<int> & ans){

    visited[src]= true;
    

    for(auto neighbour : adjList[src]){
        if(!visited[neighbour]){
            topological_sort(neighbour,adjList,visited,ans);
        }
    }

    ans.push_back(src);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // first of all make adjcencylist 

    unordered_map<int, list<int> > adjList;

    for(int i = 0 ; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }


    vector< bool> visited(v);

    vector<int> ans;

    for(int i = 0 ; i < v ; i++){
        if(!visited[i]){
            topological_sort(i,adjList, visited,ans);
        }
    }
    

    reverse(ans.begin(), ans.end());
    return ans;
}