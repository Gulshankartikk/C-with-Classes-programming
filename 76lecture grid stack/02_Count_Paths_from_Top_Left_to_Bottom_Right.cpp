#include <bits/stdc++.h>
using namespace std;

int numberOfPaths(int m, int n) {

    vector<int> dp(n, 1);

    for (int i = m - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[j] += dp[j + 1];
        }
    }

    return dp[0];
}

int main() {

    int m, n;
    cin >> m >> n;

    cout << numberOfPaths(m, n) << endl;

    return 0;
}