#include <iostream>
#include <vector>
using namespace std;

void Dfs(vector<vector<int>>& adj, vector<bool>& visit, int node) {
    if (visit[node])
        return;

    visit[node] = 1;

    for (int i = 0; i < adj[node].size(); i++) {
        if (adj[node][i])
            Dfs(adj, visit, i);
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();

    int count = 0;
    vector<bool> visit(V, 0);

    for (int i = 0; i < V; i++) {
        if (!visit[i]) {
            count++;
            Dfs(isConnected, visit, i);
        }
    }

    return count;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> isConnected(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << findCircleNum(isConnected) << endl;

    return 0;
}