#include <bits/stdc++.h>
using namespace std;

// Step 1: Normal DFS - fills stack with finish order
void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s) {
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            DFS(adj[node][i], adj, visited, s);
        }
    }
    s.push(node);
}

// Step 2: DFS on transpose graph - collects one SCC
void SSC(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &component) {
    visited[node] = 1;
    component.push_back(node);
    for (int i = 0; i < adj[node].size(); i++) {
        if (!visited[adj[node][i]]) {
            SSC(adj[node][i], visited, adj, component);
        }
    }
}

vector<vector<int>> tarjans(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> s;

    // Step 1: Fill stack according to finish time
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, adj, visited, s);
        }
    }

    // Step 2: Create transpose graph (reverse all edges)
    vector<vector<int>> transpose(V);
    for (int u = 0; u < V; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            transpose[v].push_back(u);
        }
    }

    // Step 3: Reset visited array
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    vector<vector<int>> result;

    // Step 4: Pop from stack, do DFS on transpose graph
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            vector<int> component;
            SSC(node, visited, transpose, component);
            sort(component.begin(), component.end());
            result.push_back(component);
        }
    }

    // Step 5: Sort all components lexicographically
    sort(result.begin(), result.end());
    return result;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    // Example graph edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    vector<vector<int>> sccs = tarjans(V, adj);

    cout << "Strongly Connected Components:\n";
    for (auto &component : sccs) {
        cout << "{ ";
        for (int node : component) {
            cout << node << " ";
        }
        cout << "}\n";
    }

    return 0;
}