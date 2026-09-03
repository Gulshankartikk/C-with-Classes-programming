#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    // Adjacency list
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(V);

    for (int i = 0; i < V; i++)
        dist[i] = -1;

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;

    // first = weight/dist, second = Node
    q.push({0, src});

    int Node, step;

    while (!q.empty()) {

        step = q.top().first;
        Node = q.top().second;

        q.pop();

        // Node already processed
        if (dist[Node] != -1)
            continue;

        // Store shortest distance
        dist[Node] = step;

        for (int j = 0; j < adj[Node].size(); j++) {

            int nextNode = adj[Node][j].first;
            int weight = adj[Node][j].second;

            if (dist[nextNode] == -1) {

                q.push({
                    step + weight,
                    nextNode
                });
            }
        }
    }

    return dist;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {

        cin >> edges[i][0]
            >> edges[i][1]
            >> edges[i][2];
    }

    int src;
    cin >> src;

    vector<int> ans = dijkstra(V, edges, src);

    for (int i = 0; i < V; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}