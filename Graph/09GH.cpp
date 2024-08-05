#include <bits/stdc++.h> 
using namespace std;


// topological sort using the bfs  ==> same for cycle detection using bfs in directed graph 


void topological_sort_bfs(int src,unordered_map<int, list<int> >& adjList, vector<int> & ans, int v){ 
    unordered_map<int , int> indeg;
    queue<int>q;

    // calculate indegree
    for(auto it : adjList){
        int key = it.first;

        for(auto neighbour : it.second){
            indeg[neighbour]++;
        }
    }

    //put all the nodes which indegree is zero

    for(int i = 0 ; i < v; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }


    //bfs logic 

    while(!q.empty()){
        int fNode = q.front();
        q.pop();

        ans.push_back(fNode);

        for(auto  nbr : adjList[fNode]){
            indeg[nbr]--;
            // check for zero again
            if(indeg[nbr]==0){
                q.push(nbr);
            }
        }
    }


}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    // first of all make adjcencylist 
    unordered_map<int, list<int> > adjList;

    for(int i = 0 ; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
    }


    // ans
    vector<int> ans;
    
    topological_sort_bfs(0,adjList,ans,v);  
    
    return ans;

}