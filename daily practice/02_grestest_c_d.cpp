#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minOperations(vector<int>& nums) {
    int n = nums.size();

    int overallGcd = nums[0];
    for (int i = 1; i < n; i++) {
        overallGcd = gcd(overallGcd, nums[i]);
    }

    if (overallGcd != 1)
        return -1;

    int ones = count(nums.begin(), nums.end(), 1);

    if (ones > 0)
        return n - ones;

    int minLen = n + 1;

    for (int i = 0; i < n; i++) {
        int g = 0;

        for (int j = i; j < n; j++) {
            g = gcd(g, nums[j]);

            if (g == 1) {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }

    return (minLen - 1) + (n - 1);
}

int main() {
    vector<int> nums = {2, 6, 3, 4};

    cout << minOperations(nums);

    return 0;
}