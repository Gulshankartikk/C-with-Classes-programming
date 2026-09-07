#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

bool isCircle(vector<string> &arr) {

    vector<int> inDegree(26, 0);
    vector<int> outDegree(26, 0);

    // Undirected graph for connectivity
    vector<int> adj[26];

    for (string s : arr) {

        int u = s.front() - 'a';
        int v = s.back() - 'a';

        outDegree[u]++;
        inDegree[v]++;

        // For connectivity, consider edge as undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Every vertex must have equal in-degree and out-degree
    for (int i = 0; i < 26; i++) {
        if (inDegree[i] != outDegree[i]) {
            return false;
        }
    }

    // Find a character that actually appears
    int start = -1;

    for (int i = 0; i < 26; i++) {
        if (inDegree[i] + outDegree[i] > 0) {
            start = i;
            break;
        }
    }

    if (start == -1) {
        return false;
    }

    // Check connectivity
    vector<bool> visited(26, false);

    dfs(start, adj, visited);

    for (int i = 0; i < 26; i++) {
        if (inDegree[i] + outDegree[i] > 0 &&
            !visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (isCircle(arr)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}