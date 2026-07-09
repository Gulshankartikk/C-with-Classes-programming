#include <iostream>
#include <vector>
using namespace std;

bool DetectCycle(vector<int> adj[], int node, int parent, vector<bool>& visited) {
    visited[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            if (DetectCycle(adj, adj[node][i], node, visited))
                return true;
        }
        else if (parent != adj[node][i]) {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {

    vector<int> adj[V];

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (DetectCycle(adj, i, -1, visited))
                return true;
        }
    }

    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (isCycle(V, edges))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}