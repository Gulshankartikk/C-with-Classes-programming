#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> weight(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);

    int count = 0, cost = 0;

    vector<vector<pair<int, int>>> adj(V);

    for (auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> q;

    q.push({0, 0});

    int Node, path, adjNode, adjPath;

    while (!q.empty())
    {
        path = q.top().first;
        Node = q.top().second;
        q.pop();

        if (visited[Node] == 1)
            continue;

        visited[Node] = 1;
        cost += path;

        for (int i = 0; i < adj[Node].size(); i++)
        {
            adjNode = adj[Node][i].first;
            adjPath = adj[Node][i].second;

            if (!visited[adjNode] && adjPath < weight[adjNode])
            {
                q.push({adjPath, adjNode});
                parent[adjNode] = Node;
                weight[adjNode] = adjPath;
            }
        }
    }

    cout << cost;

    return 0;
}