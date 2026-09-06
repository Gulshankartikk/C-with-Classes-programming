#include <bits/stdc++.h>
using namespace std;

bool DFS(int node, int target, vector<int> adj[], vector<bool> &visited) {
    if (node == target)
        return 1;
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            if (DFS(adj[node][i], target, adj, visited))
                return 1;
        }
    }
    return 0;
}

bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
    // Code here
    vector<int> adj[V];
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < adj[c].size(); i++) {
        if (adj[c][i] == d) {
            adj[c][i] = c;
            break;
        }
    }
    for (int i = 0; i < adj[d].size(); i++) {
        if (adj[d][i] == c) {
            adj[d][i] = d;
            break;
        }
    }
    vector<bool> visited(V, 0);
    // 1: target node found
    // 0: target node not found -> bridge hai 1;
    return !DFS(c, d, adj, visited);
}

int main() {
    int V = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {0, 3}, {1, 3}};

    int c = 1, d = 3;

    bool result = isBridge(V, edges, c, d);

    if (result)
        cout << "Edge (" << c << ", " << d << ") is a bridge" << endl;
    else
        cout << "Edge (" << c << ", " << d << ") is NOT a bridge" << endl;

    return 0;
}