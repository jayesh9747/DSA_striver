#include <bits/stdc++.h>
using namespace std;

//  Graph representation using the adjacency list

// if we want to make the general so make template

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, int direction)
    {

        // direction == 0 ->  undirected graph
        // direction == 1 -> directed graph

        //  u -> key m , v = list
        //  create edge from u to v
        adjList[u].push_back(v);

        if (direction == 0)
        {
            // undirected graph
            // create edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "->";

            for (auto j : node.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    void bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            cout << frontNode << ", ";

            // insert neighbour
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {

        cout << src << ", ";
        visited[src] = true;

        // insert neighbour
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{

    // Graph<char> g;
    // g.addEdge('a','b',1);
    // g.addEdge('a','c',1);
    // g.addEdge('b','c',1);

    Graph<int> g;

    int n = 5;

    // un-direct edge input
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);

    g.printAdjacencyList();

    cout << endl;

    // if graph is  disconnected

    cout << "printing the BFS traversal" << endl;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    cout << endl << "printing the DFS traversal" << endl;
    unordered_map<int, bool> visited2;

    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    // un-direct edge input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    // directed edge input

    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);

    // g.printAdjacencyList();
}