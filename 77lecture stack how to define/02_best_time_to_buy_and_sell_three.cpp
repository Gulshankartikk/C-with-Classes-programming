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

/*class Solution {
public:
    

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3,vector<int>(n+1,0));

        int total;
        for(int i=1;i<=2;i++)
        {
            total =-prices[0];
            for(int j=2;j<=n;j++)
            {
                dp[i][j]=max(dp[i][j-1],prices[j-1]+total);
                total =max(total, -prices[j-1]+dp[i-1][j]);
            }
        };
        return dp[2][n];
    }
};*/