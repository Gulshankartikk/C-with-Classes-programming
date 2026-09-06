#include <bits/stdc++.h>
using namespace std;

void Bellmon(vector<vector<int>>& edges, vector<int>& dist)
{
    for (int i = 0; i < edges.size(); i++)
    {
        if (dist[edges[i][0]] != 1e8 &&
            dist[edges[i][0]] + edges[i][2] < dist[edges[i][1]])
        {
            dist[edges[i][1]] = dist[edges[i][0]] + edges[i][2];
        }
    }
}

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        Bellmon(edges, dist);
    }
    vector<int> ans(V);
    for (int i = 0; i < V; i++)
        ans[i] = dist[i];
    Bellmon(edges, dist);
    for (int i = 0; i < V; i++)
    {
        if (ans[i] != dist[i])
        {
            vector<int> temp;
            temp.push_back(-1);
            return temp;
        }
    }
    return ans;
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

    int src;
    cin >> src;

    vector<int> result = bellmanFord(V, edges, src);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}