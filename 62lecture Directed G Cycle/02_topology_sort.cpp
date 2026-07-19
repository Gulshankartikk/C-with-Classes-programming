#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFS(vector<int> adj[], stack<int> &s, vector<bool> &visit, int node) {
    visit[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        if (!visit[adj[node][i]]) {
            DFS(adj, s, visit, adj[node][i]);
        }
    }

    s.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &edges) {

    // Build adjacency list
    vector<int> adj[V];

    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
    }

    stack<int> s;
    vector<bool> visit(V, false);

    for (int i = 0; i < V; i++) {
        if (!visit[i]) {
            DFS(adj, s, visit, i);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(2));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> ans = topoSort(V, edges);

    cout << "Topological Order: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}