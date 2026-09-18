#include <bits/stdc++.h>
using namespace std;

int uniquePaths(vector<vector<int>> &grid) {

    int a = grid.size();
    int b = grid[0].size();

    vector<vector<int>> dp(a, vector<int>(b, 0));

    // If starting or ending cell is blocked
    if (grid[0][0] == 1 || grid[a - 1][b - 1] == 1)
        return 0;

    // Destination
    dp[a - 1][b - 1] = 1;

    // Same bottom-up logic
    for (int i = a - 1; i >= 0; i--) {
        for (int j = b - 1; j >= 0; j--) {

            // Blocked cell
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            // Destination already initialized
            if (i == a - 1 && j == b - 1)
                continue;

            if (i + 1 < a)
                dp[i][j] += dp[i + 1][j];

            if (j + 1 < b)
                dp[i][j] += dp[i][j + 1];
        }
    }

    return dp[0][0];
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << uniquePaths(grid) << endl;

    return 0;
}