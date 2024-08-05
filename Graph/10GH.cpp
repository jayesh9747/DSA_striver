#include <bits/stdc++.h>
using namespace std;



//  shortest distance using BFS on undirected graph

vector<int> solveusingBFS(unordered_map<int, list<int>>& adjList,unordered_map<int , bool >& visited,unordered_map<int, int>& parent, int s , int t){
	queue<int> q;
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int frontNode = q.front();
		q.pop();

		for(auto nbr : adjList[frontNode]){
			if(!visited[nbr]){
				visited[nbr] = true;
				parent[nbr] = frontNode;
				q.push(nbr);
			}
		}
	}

	vector<int> ans;
	ans.push_back(t); 

	while(ans.back() != s){
		ans.push_back(parent[t]);
		t= parent[t];
	}


	return ans;
}



vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// make the adjacency list 

	unordered_map<int, list<int>> adjList;

	for(int i = 0 ; i < edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	unordered_map<int , bool > visited;
	unordered_map<int, int> parent;

	vector<int> ans = solveusingBFS(adjList , visited , parent,s,t);

	reverse(ans.begin(), ans.end());

	return ans;
	
}
