#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int i, int j, int row, int col) {
    return i > -1 && i < row && j > -1 && j < col;
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();   // row
    int m = grid[0].size(); // col

    int goodOranges = 0;

    // row, col, timer
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            // count fresh oranges
            if (grid[i][j] == 1)
                goodOranges++;

            // push rotten oranges
            else if (grid[i][j] == 2)
                q.push({{i, j}, 0});
        }

    int i, j, timer = 0;

    while (!q.empty()) {
        i = q.front().first.first;
        j = q.front().first.second;
        timer = q.front().second;
        q.pop();

        // up
        if (check(i - 1, j, n, m) && grid[i - 1][j] == 1) {
            grid[i - 1][j] = 0;
            goodOranges--;
            q.push({{i - 1, j}, timer + 1});
        }

        // down
        if (check(i + 1, j, n, m) && grid[i + 1][j] == 1) {
            grid[i + 1][j] = 0;
            goodOranges--;
            q.push({{i + 1, j}, timer + 1});
        }

        // left
        if (check(i, j - 1, n, m) && grid[i][j - 1] == 1) {
            grid[i][j - 1] = 0;
            goodOranges--;
            q.push({{i, j - 1}, timer + 1});
        }

        // right
        if (check(i, j + 1, n, m) && grid[i][j + 1] == 1) {
            grid[i][j + 1] = 0;
            goodOranges--;
            q.push({{i, j + 1}, timer + 1});
        }
    }

    if (goodOranges)
        return -1;
    else
        return timer;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    cout << orangesRotting(grid) << endl;

    return 0;
}