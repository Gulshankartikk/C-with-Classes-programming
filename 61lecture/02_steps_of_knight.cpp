#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check(int i, int j, int n)
{
    return i > 0 && j > 0 && i <= n && j <= n;
}

int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n)
{
    int row[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int col[8] = {1, -1, 1, -1, 2, -2, 2, -2};

    queue<pair<pair<int, int>, int>> q;
    q.push({{knightPos[0], knightPos[1]}, 0});

    vector<vector<bool>> visit(n + 1, vector<bool>(n + 1, false));
    visit[knightPos[0]][knightPos[1]] = true;

    int i, j, step = 0;

    while (!q.empty())
    {
        i = q.front().first.first;
        j = q.front().first.second;
        step = q.front().second;
        q.pop();

        if (i == targetPos[0] && j == targetPos[1])
            return step;

        for (int k = 0; k < 8; k++)
        {
            if (check(i + row[k], j + col[k], n) &&
                !visit[i + row[k]][j + col[k]])
            {
                visit[i + row[k]][j + col[k]] = true;
                q.push({{i + row[k], j + col[k]}, step + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> knightPos(2), targetPos(2);

    cin >> knightPos[0] >> knightPos[1];
    cin >> targetPos[0] >> targetPos[1];

    cout << minStepToReachTarget(knightPos, targetPos, n) << endl;

    return 0;
}