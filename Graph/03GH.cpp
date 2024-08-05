#include<bits/stdc++.h>
using namespace std;

//  weighted Graph



class Graph {
    public : 

    unordered_map<int , list<pair<int,int>> > adjList; 

    void addEdge(int u , int v , int weight ,int direction){

        // direction == 0 ->  undirected graph
        // direction == 1 -> directed graph 

        //  u -> key m , v = list 
        //  create edge from u to v 
        adjList[u].push_back({v,weight});

        if(direction == 0 ){
            // undirected graph
            // create edge from v to u 
            adjList[v].push_back({u, weight});
        }
    }


    void printAdjacencyList(){
        for(auto node : adjList){
            cout << node.first << "->";

            for(auto neighbour : node.second){
                cout << "(" << neighbour.first << "," << neighbour.second <<"),";
            }
            cout << endl;
        }
    }

};


int main(){

    Graph g;

    // un-direct edge input 
    // g.addEdge(srcNode, destNode, weightNode , direction)
    g.addEdge(0,1,5,0);
    g.addEdge(1,2,4,0); 
    g.addEdge(0,2,3,0);


    // directed edge input 
    // g.addEdge(srcNode, destNode, weightNode , direction)
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);


    cout << endl;

    g.printAdjacencyList();

    
}