#include <bits/stdc++.h>
using namespace std;

// DFS to check connectivity
void DFS(int node, vector<int> adj[], vector<bool>& visited)
{
    visited[node] = 1;

    for(int i = 0; i < adj[node].size(); i++)
    {
        if(!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}

int isEulerCircuit(int V, vector<vector<int>>& adj)
{
    // Calculate degree of every vertex
    vector<int> degree(V, 0);

    for(int i = 0; i < V; i++)
        degree[i] = adj[i].size();

    // Find a vertex having at least one edge
    int node = -1;

    for(int i = 0; i < V; i++)
    {
        if(degree[i])
        {
            node = i;
            break;
        }
    }

    // If there are no edges, it is an Euler Circuit
    if(node == -1)
        return 2;

    // Count vertices having odd degree
    int odd = 0;

    for(int i = 0; i < V; i++)
    {
        if(degree[i] % 2)
            odd++;
    }

    // More than 2 odd-degree vertices means no Euler Path/Circuit
    if(odd != 0 && odd != 2)
        return 0;

    // Check whether all vertices with edges are connected
    vector<bool> visited(V, 0);
    DFS(node, adj.data(), visited);

    // If any vertex with an edge is not visited, graph is disconnected
    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && degree[i])
            return 0;
    }

    // Exactly 2 odd-degree vertices means Euler Path
    if(odd == 2)
        return 1;

    // All vertices have even degree means Euler Circuit
    return 2;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isEulerCircuit(V, adj);

    return 0;
}