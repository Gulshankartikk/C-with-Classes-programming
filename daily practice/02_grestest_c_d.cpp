#include <iostream>
#include <vector>
#include <algorithm>  // for count(), min()
#include <climits>    // for INT_MAX

using namespace std;

// ✅ Custom gcd function (works for all C++ versions)
int myGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int minOperations(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Check overall GCD
    int overall_gcd = nums[0];
    for (int i = 1; i < n; i++) {
        overall_gcd = myGCD(overall_gcd, nums[i]);
    }
    if (overall_gcd != 1) return -1; // impossible case

    // Step 2: If any element is already 1
    int ones = count(nums.begin(), nums.end(), 1);
    if (ones > 0) return n - ones;

    // Step 3: Find shortest subarray with gcd == 1
    int min_len = INT_MAX;
    for (int i = 0; i < n; i++) {
        int g = nums[i];
        for (int j = i; j < n; j++) {
            g = myGCD(g, nums[j]);
            if (g == 1) {
                min_len = min(min_len, j - i + 1);
                break; // found shortest for this i
            }
        }
    }

    // Step 4: (length to make 1 - 1) + (n - 1)
    return (min_len - 1) + (n - 1);
}

int main() {
    vector<int> nums1 = {2, 6, 3, 4};
    vector<int> nums2 = {2, 10, 6, 14};

    cout << "Example 1: " << minOperations(nums1) << endl;  // Output: 4
    cout << "Example 2: " << minOperations(nums2) << endl;  // Output: -1

    return 0;
}
