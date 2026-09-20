#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(3, vector<int>(n + 1, 0));

    for (int i = 1; i <= 2; i++) {
        int total = -prices[0];

        for (int j = 2; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + total);
            total = max(total, dp[i - 1][j] - prices[j - 1]);
        }
    }

    return dp[2][n];
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << endl;
    return 0;
}