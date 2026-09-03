#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>>& edges, int src, int dest) {

    // Adjacency list
    vector<vector<pair<int, int>>> adj(V + 1);

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Dijkstra from destination
    vector<long long> dist(V + 1, LLONG_MAX);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[dest] = 0;
    pq.push({0, dest});

    while (!pq.empty()) {

        long long d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d != dist[node])
            continue;

        for (auto &it : adj[node]) {

            int neighbor = it.first;
            int weight = it.second;

            if (d + weight < dist[neighbor]) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Destination unreachable
    if (dist[src] == LLONG_MAX)
        return {-1};

    // Build lexicographically smallest shortest path
    vector<int> path;

    int node = src;
    path.push_back(node);

    while (node != dest) {

        int nextNode = -1;

        for (auto &it : adj[node]) {

            int neighbor = it.first;
            int weight = it.second;

            // This edge belongs to a shortest path
            if (dist[node] == weight + dist[neighbor]) {

                // Choose smallest possible next node
                if (nextNode == -1 || neighbor < nextNode) {
                    nextNode = neighbor;
                }
            }
        }

        if (nextNode == -1)
            return {-1};

        node = nextNode;
        path.push_back(node);
    }

    return path;
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

    int src, dest;
    cin >> src >> dest;

    vector<int> ans = shortestPath(V, edges, src, dest);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}