#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(int node, vector<vector<int>>& adj,
               vector<bool>& vis, vector<int>& ans) {
    vis[node] = true;
    ans.push_back(node);

    for (int x : adj[node]) {
        if (!vis[x]) {
            dfsHelper(x, adj, vis, ans);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<bool> vis(V, false);
    vector<int> ans;

    dfsHelper(0, adj, vis, ans);

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

    vector<int> ans = dfs(adj);

    cout << "DFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}