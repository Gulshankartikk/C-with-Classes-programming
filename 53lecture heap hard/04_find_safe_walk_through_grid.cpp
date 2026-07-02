#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> best(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    int startHealth = health - grid[0][0];
    if (startHealth <= 0)
        return false;

    q.push({0, 0});
    best[0][0] = startHealth;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        int curHealth = best[x][y];

        if (x == m - 1 && y == n - 1)
            return true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;

            int newHealth = curHealth - grid[nx][ny];

            if (newHealth <= 0)
                continue;

            if (newHealth > best[nx][ny]) {
                best[nx][ny] = newHealth;
                q.push({nx, ny});
            }
        }
    }

    return false;
}

int main() {
    int m, n, health;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> health;

    if (findSafeWalk(grid, health))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}