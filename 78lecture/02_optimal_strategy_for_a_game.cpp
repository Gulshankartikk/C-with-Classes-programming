#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<long long, long long>>> dp;
vector<vector<bool>> visited;

// Returns {current player's money, opponent's money}
pair<long long, long long> solve(int i, int j, vector<int>& arr) {
    if (i > j)
        return {0, 0};

    if (visited[i][j])
        return dp[i][j];

    visited[i][j] = true;

    pair<long long, long long> left = solve(i + 1, j, arr);
    pair<long long, long long> takeFirst = {
        arr[i] + left.second,
        left.first
    };

    pair<long long, long long> right = solve(i, j - 1, arr);
    pair<long long, long long> takeLast = {
        arr[j] + right.second,
        right.first
    };

    if (takeFirst.first > takeLast.first)
        return dp[i][j] = takeFirst;

    return dp[i][j] = takeLast;
}

int maximumAmount(vector<int>& arr) {
    int n = arr.size();

    dp.resize(n, vector<pair<long long, long long>>(n));
    visited.resize(n, vector<bool>(n, false));

    return solve(0, n - 1, arr).first;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maximumAmount(arr) << endl;

    return 0;
}