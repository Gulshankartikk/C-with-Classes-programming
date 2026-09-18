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