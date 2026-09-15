#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int n = wt.size();

    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= wt[i - 1]; j--) {
            dp[j] = max(val[i - 1] + dp[j - wt[i - 1]], dp[j]);
        }
    }

    return dp[W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int W = 50;

    cout << knapsack(W, val, wt);

    return 0;
}