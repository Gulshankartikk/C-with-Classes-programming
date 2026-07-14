#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int i, int j, int row, int col)
{
    return i > -1 && i < row && j > -1 && j < col;
}

void BFS(vector<vector<char>> &grid, int i, int j)
{
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = '0';

    while (!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            if (check(i + row[k], j + col[k], n, m) &&
                grid[i + row[k]][j + col[k]] == '1')
            {
                grid[i + row[k]][j + col[k]] = '0';
                q.push({i + row[k], j + col[k]});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                BFS(grid, i, j);
            }
        }
    }

    return count;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    cout << numIslands(grid);

    return 0;
}