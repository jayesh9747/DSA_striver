class Solution
{
public:
    // minimum cost from the src to the each node (in directed acyclic graph) {GFG}

    void topological_sort_using_DFS(unordered_map<int, list<pair<int, int>>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int src)
    {

        visited[src] = true;

        for (auto &nbr : adjList[src])
        {
            if (!visited[nbr.first])
            {
                topological_sort_using_DFS(adjList, visited, ans, nbr.first);
            }
        }

        ans.push_back(src);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        // first  of all make the  adj list

        unordered_map<int, list<pair<int, int>>> adjList;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjList[u].push_back({v, w});
        }

        unordered_map<int, bool> visited;
        vector<int> ans;
        topological_sort_using_DFS(adjList, visited, ans, 0);

        reverse(ans.begin(), ans.end());

        vector<int> dis(N, INT_MAX);

        dis[0] = 0;

        for (int i = 0; i < ans.size(); i++)
        {

            if (dis[ans[i]] != INT_MAX)
            {

                for (auto it : adjList[ans[i]])
                {
                    if (dis[ans[i]] + it.second < dis[it.first])
                    {
                        dis[it.first] = dis[ans[i]] + it.second;
                    }
                }
            }
        }

        for (int i = 0; i < dis.size(); i++)
        {
            if (dis[i] == INT_MAX)
            {
                dis[i] = -1;
            }
        }

        return dis;
    }
};