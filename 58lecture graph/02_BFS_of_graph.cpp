#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    int V = adj.size();

    vector<int> ans;
    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];

            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }

    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line for a directed graph
    }

    vector<int> ans = bfs(adj);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}