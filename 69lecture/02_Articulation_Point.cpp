#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<int>& disc, vector<int>& low,
         vector<int>& ans, int& timer, int parent)
{
    disc[node] = low[node] = ++timer;

    int children = 0;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbour = adj[node][i];

        if (neighbour == parent)
            continue;

        if (disc[neighbour] == -1)
        {
            children++;

            DFS(neighbour, adj, disc, low, ans, timer, node);

            low[node] = min(low[node], low[neighbour]);

            // Articulation point condition
            if (parent != -1 && low[neighbour] >= disc[node])
                ans.push_back(node);
        }
        else
        {
            low[node] = min(low[node], disc[neighbour]);
        }
    }

    // Root articulation point condition
    if (parent == -1 && children > 1)
        ans.push_back(node);
}

vector<int> articulationPoints(int V, vector<vector<int>>& edges)
{
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> ans;

    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int timer = 0;

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == -1)
            DFS(i, adj, disc, low, ans, timer, -1);
    }

    sort(ans.begin(), ans.end());

    // Remove duplicates
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    if (ans.size() == 0)
        ans.push_back(-1);

    return ans;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    vector<int> ans = articulationPoints(V, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}