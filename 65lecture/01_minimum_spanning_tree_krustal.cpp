#include <bits/stdc++.h>
using namespace std;

int findPar(int u, vector<int>& parent)
{
    if (u == parent[u])
        return u;

    return parent[u] = findPar(parent[u], parent);
}

bool unionSet(int u, int v, vector<int>& rank, vector<int>& parent)
{
    int pu = findPar(u, parent);
    int pv = findPar(v, parent);

    if (pu == pv)
        return 1;

    if (rank[pu] == rank[pv])
    {
        rank[pu]++;
        parent[pv] = pu;
    }
    else if (rank[pu] < rank[pv])
    {
        parent[pu] = pv;
    }
    else
    {
        parent[pv] = pu;
    }

    return 0;
}

int spanningTree(int V, vector<vector<int>>& edges)
{
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    priority_queue<
        pair<pair<int, int>, int>,
        vector<pair<pair<int, int>, int>>,
        greater<pair<pair<int, int>, int>>
    > q;

    int u, v, w;

    for (int i = 0; i < edges.size(); i++)
    {
        u = edges[i][0];
        v = edges[i][1];
        w = edges[i][2];

        q.push({{w, u}, v});
    }

    int count_edge = 0, cost = 0;

    while (!q.empty())
    {
        if (count_edge == V - 1)
            break;

        w = q.top().first.first;
        u = q.top().first.second;
        v = q.top().second;

        q.pop();

        if (unionSet(u, v, rank, parent))
            continue;

        count_edge++;
        cost += w;
    }

    return cost;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << spanningTree(V, edges) << endl;

    return 0;
}