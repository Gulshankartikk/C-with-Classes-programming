#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    else
        return edges[0][1];
}

int main() {
    int n;
    cin >> n; // number of edges

    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    cout << findCenter(edges) << endl;

    return 0;
}