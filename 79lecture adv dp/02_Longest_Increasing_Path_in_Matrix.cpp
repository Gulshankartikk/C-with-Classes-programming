#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool check(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void DFS(int i, int j, vector<vector<int>> &matrix,
         vector<vector<int>> &path, int n, int m)
{
    path[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int ni = i + row[k];
        int nj = j + col[k];

        if (check(ni, nj, n, m) &&
            matrix[i][j] < matrix[ni][nj])
        {
            if (path[ni][nj] == 0)
            {
                DFS(ni, nj, matrix, path, n, m);
            }

            path[i][j] = max(path[i][j], 1 + path[ni][nj]);
        }
    }
}

int longIncPath(vector<vector<int>> &matrix, int n, int m)
{
    vector<vector<int>> path(n, vector<int>(m, 0));

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (path[i][j] == 0)
            {
                DFS(i, j, matrix, path, n, m);
            }

            total = max(total, path[i][j]);
        }
    }

    return total;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << longIncPath(matrix, n, m) << endl;

    return 0;
}