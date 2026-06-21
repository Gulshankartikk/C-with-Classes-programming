#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int count = 0;

    for (int cost : costs) {
        if (coins >= cost) {
            coins -= cost;
            count++;
        } else {
            break;
        }
    }

    return count;
}

int main() {
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;

    cout << maxIceCream(costs, coins) << endl;

    return 0;
}