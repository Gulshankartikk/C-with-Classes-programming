#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();

    for (int j = m - 2; j >= 0; j--)
        grid[n - 1][j] += grid[n - 1][j + 1];

    for (int i = n - 2; i >= 0; i--)
        grid[i][m - 1] += grid[i + 1][m - 1];

    for (int i = n - 2; i >= 0; i--)
        for (int j = m - 2; j >= 0; j--)
            grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);

    return grid[0][0];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << minPathSum(grid) << '\n';
    return 0;
}