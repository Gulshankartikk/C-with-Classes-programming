#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>> &adj, vector<bool> &visited,
         vector<bool> &path, int node) {

    visited[node] = true;
    path[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int neigh = adj[node][i];

        if (!visited[neigh]) {
            if (DFS(adj, visited, path, neigh))
                return true;
        }
        else if (path[neigh]) {
            return true;
        }
    }

    path[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &adj) {

    vector<bool> visited(V, false);
    vector<bool> path(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DFS(adj, visited, path, i))
                return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   // Directed graph
    }

    if (isCyclic(V, adj))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}