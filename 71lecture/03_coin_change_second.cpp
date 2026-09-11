#include <iostream>
#include <vector>
using namespace std;

int find(int index, int amount, vector<int>& coins,
         int n, vector<vector<int>>& dp) {

    // Base case
    if (amount == 0)
        return 1;

    if (amount < 0 || index >= n)
        return 0;

    // Already calculated
    if (dp[index][amount] != -1)
        return dp[index][amount];

    // Use the current coin
    int use = find(index, amount - coins[index],
                   coins, n, dp);

    // Skip the current coin
    int skip = find(index + 1, amount,
                    coins, n, dp);

    return dp[index][amount] = use + skip;
}

int main() {

    int amount = 5;
    vector<int> coins = {1, 2, 5};

    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int ans = find(0, amount, coins, n, dp);

    cout << "Number of combinations: " << ans << endl;

    return 0;
}