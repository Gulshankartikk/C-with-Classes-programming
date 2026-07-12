#include <iostream>
#include <vector>
using namespace std;

// Function to create adjacency list
vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(V);

    // Add edges in both directions (Undirected Graph)
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return adj;
}

int main() {
    int V = 5;

    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {4, 1},
        {4, 3},
        {1, 3},
        {1, 2},
        {3, 2}
    };

    vector<vector<int>> adj = printGraph(V, edges);

    cout << "Adjacency List:" << endl;

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int node : adj[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}