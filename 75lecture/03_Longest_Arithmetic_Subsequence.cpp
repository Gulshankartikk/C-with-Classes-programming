#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();

    if (n <= 2)
        return n;

    unordered_map<int, int> m[n];

    int ans = 2;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            int d = nums[i] - nums[j];

            if (m[j].count(d)) {
                m[i][d] = m[j][d] + 1;
            }
            else {
                m[i][d] = 2;
            }

            ans = max(ans, m[i][d]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << longestArithSeqLength(nums) << endl;

    return 0;
}