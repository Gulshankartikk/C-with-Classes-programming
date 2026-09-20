#include <bits/stdc++.h>
using namespace std;

int find(int day, int trans, int buy, int n, vector<int>& prices,
         vector<vector<vector<int>>>& dp) {
    
    if (trans == 0 || day == n)
        return 0;

    if (dp[day][trans][buy] != -1)
        return dp[day][trans][buy];

    if (buy) {
        return dp[day][trans][buy] = max(
            -prices[day] + find(day + 1, trans, 0, n, prices, dp),
            find(day + 1, trans, 1, n, prices, dp)
        );
    } else {
        return dp[day][trans][buy] = max(
            prices[day] + find(day + 1, trans - 1, 1, n, prices, dp),
            find(day + 1, trans, 0, n, prices, dp)
        );
    }
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(3, vector<int>(2, -1))
    );

    cout << find(0, 2, 1, n, prices, dp);

    return 0;
}