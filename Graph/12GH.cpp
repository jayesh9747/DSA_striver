#include <bits/stdc++.h> 
using namespace std;

//  dijkstra algorithm 

vector<int> solveusingDijkstra(unordered_map<int , list<pair<int, int>>>& adjList, int src, int v , int e){

    vector<int> dis(v, INT_MAX);
    set<pair<int,int>> st;

    // initial steps 
    dis[src] = 0;
    st.insert(make_pair(0,src));

    while(!st.empty()){
        // fetch the smallest cost or first value pair from the set 
        auto top = *st.begin();

        int nodeDistance = top.first;
        int node = top.second;

        // pop from set 

        st.erase(st.begin());

        // traverse the neighbour 

        for(auto nbr : adjList[node]){
            if(nodeDistance + nbr.second < dis[nbr.first]){
                // muje distance update karna hai 

                // find the entry in the set or not 

                auto result = st.find(make_pair( dis[nbr.first] , nbr.first));

                // if entry is found , then  remove this entry
                if(result != st.end()){
                    st.erase(result);
                }
                
                dis[nbr.first] = nodeDistance + nbr.second;
                st.insert(make_pair( dis[nbr.first] ,nbr.first));
            }
        }

    }

    return dis;

}


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // create the adjecency list 

    unordered_map<int , list<pair<int, int>>> adjList;

    for(int i = 0; i < vec.size() ; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> ans;

    ans = solveusingDijkstra(adjList,source,vertices, edges);

    return ans;
}
