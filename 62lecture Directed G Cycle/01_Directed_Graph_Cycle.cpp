#include <iostream>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>> &adj, vector<bool> &visited,
         vector<bool> &path, int node) {

    visited[node] = true;
    path[node] = true;

    for (int next : adj[node]) {
        if (!visited[next]) {
            if (DFS(adj, visited, path, next))
                return true;
        }
        else if (path[next]) {
            return true;
        }
    }

    path[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {

    // Build adjacency list
    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

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

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    if (isCyclic(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}