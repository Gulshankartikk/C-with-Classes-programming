#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void fillGrid(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    queue<pair<int, int>> q;

    // Answer matrix (default all X)
    vector<vector<char>> ans(n, vector<char>(m, 'X'));

    // Visited matrix
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    // First row
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 'O') {
            q.push({0, j});
            visit[0][j] = true;
            ans[0][j] = 'O';
        }
    }

    // Last row
    for (int j = 0; j < m; j++) {
        if (grid[n - 1][j] == 'O' && !visit[n - 1][j]) {
            q.push({n - 1, j});
            visit[n - 1][j] = true;
            ans[n - 1][j] = 'O';
        }
    }

    // First column
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 'O' && !visit[i][0]) {
            q.push({i, 0});
            visit[i][0] = true;
            ans[i][0] = 'O';
        }
    }

    // Last column
    for (int i = 0; i < n; i++) {
        if (grid[i][m - 1] == 'O' && !visit[i][m - 1]) {
            q.push({i, m - 1});
            visit[i][m - 1] = true;
            ans[i][m - 1] = 'O';
        }
    }

    // BFS
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nr = u + row[k];
            int nc = v + col[k];

            if (check(nr, nc, n, m) &&
                !visit[nr][nc] &&
                grid[nr][nc] == 'O') {

                visit[nr][nc] = true;
                ans[nr][nc] = 'O';
                q.push({nr, nc});
            }
        }
    }

    grid = ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    fillGrid(grid);

    cout << "Modified Grid:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}