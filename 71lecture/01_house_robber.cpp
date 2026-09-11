#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int index, vector<int>& nums, int n, vector<int>& dp)
{
    // Base condition
    if (index >= n)
        return 0;

    // Already calculated
    if (dp[index] != -1)
        return dp[index];

    return dp[index] = max(
        nums[index] + find(index + 2, nums, n, dp),
        find(index + 1, nums, n, dp)
    );
}

int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};

    int n = nums.size();

    vector<int> dp(n + 2, -1);

    cout << "Maximum amount robbed: "
         << find(0, nums, n, dp) << endl;

    return 0;
}