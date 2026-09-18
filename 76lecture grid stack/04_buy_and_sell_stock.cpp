#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0, n = prices.size();
    int stock = prices[0];

    for (int i = 1; i < n; i++) {
        profit = max(profit, prices[i] - stock);
        stock = min(stock, prices[i]);
    }

    return profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << maxProfit(prices) << '\n';
    return 0;
}
//part two
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, n = prices.size();
        

        for (int i = 1; i < n; i++) {
            if(prices[i]>prices[i-1])
            profit+=prices[i]-prices[i-1];
        }

        return profit;
    }
};*/