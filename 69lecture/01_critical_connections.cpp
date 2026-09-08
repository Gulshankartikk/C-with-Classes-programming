#include <bits/stdc++.h>
using namespace std;

int DFS(int node, vector<int> adj[], vector<int>& disc, vector<int>& low,
        vector<vector<int>>& bridge, int& timer, int parent)
{
    if (disc[node] != -1)
        return disc[node];

    timer++;
    disc[node] = low[node] = timer;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int neighbour = adj[node][i];

        if (neighbour == parent)
            continue;

        low[node] = min(low[node],
            DFS(neighbour, adj, disc, low, bridge, timer, node));

        // bridge condition
        if (low[neighbour] > disc[node])
        {
            if (node > neighbour)
                bridge.push_back({neighbour, node});
            else
                bridge.push_back({node, neighbour});
        }
    }

    return low[node];
}

vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges)
{
    vector<vector<int>> bridge;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);

    vector<int> adj[v];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int w = edges[i][1];

        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int timer = -1;
    int parent = -1;

    DFS(0, adj, disc, low, bridge, timer, parent);

    sort(bridge.begin(), bridge.end());

    return bridge;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, w;
        cin >> u >> w;

        edges.push_back({u, w});
    }

    vector<vector<int>> bridge = criticalConnections(v, edges);

    for (int i = 0; i < bridge.size(); i++)
    {
        cout << bridge[i][0] << " " << bridge[i][1] << endl;
    }

    return 0;
}