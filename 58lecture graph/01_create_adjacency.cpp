#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<int> A[v];
    int a, b;

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }

    vector<bool> visited(v, false);
    vector<int> ans;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int x : A[node]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout << "BFS Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}