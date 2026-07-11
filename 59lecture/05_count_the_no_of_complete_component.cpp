#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis,
         int &nodes, int &degreeSum) {
    vis[node] = true;
    nodes++;
    degreeSum += adj[node].size();

    for (int nei : adj[node]) {
        if (!vis[nei]) {
            dfs(nei, adj, vis, nodes, degreeSum);
        }
    }
}

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n, false);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            int nodes = 0;
            int degreeSum = 0;

            dfs(i, adj, vis, nodes, degreeSum);

            if (degreeSum == nodes * (nodes - 1))
                ans++;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << countCompleteComponents(n, edges) << endl;

    return 0;
}