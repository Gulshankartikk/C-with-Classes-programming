#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

    vector<pair<double, pair<int, int>>> v;

    for (int i = 0; i < val.size(); i++) {
        v.push_back({
            (double)val[i] / wt[i],
            {val[i], wt[i]}
        });
    }

    sort(v.rbegin(), v.rend());

    double ans = 0;

    for (auto x : v) {

        int value = x.second.first;
        int weight = x.second.second;

        if (capacity >= weight) {
            ans += value;
            capacity -= weight;
        }
        else {
            ans += (double)value / weight * capacity;
            break;
        }
    }

    return ans;
}

int main() {

    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};

    int capacity = 50;

    cout << fractionalKnapsack(val, wt, capacity) << endl;

    return 0;
}