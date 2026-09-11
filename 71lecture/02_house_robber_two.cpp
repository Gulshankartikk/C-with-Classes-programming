#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int index, int n, vector<int>& nums, vector<int>& dp)
{
    // Base condition
    if (index >= n)
        return 0;

    // Already calculated
    if (dp[index] != -1)
        return dp[index];

    return dp[index] = max(
        nums[index] + find(index + 2, n, nums, dp),
        find(index + 1, n, nums, dp)
    );
}

int main()
{
    vector<int> nums = {2, 3, 2};

    int n = nums.size();

    if (n == 1)
    {
        cout << "Maximum amount robbed: " << nums[0] << endl;
        return 0;
    }

    vector<int> dp1(n + 2, -1);
    vector<int> dp2(n + 2, -1);

    int ans = max(
        find(0, n - 1, nums, dp1),
        find(1, n, nums, dp2)
    );

    cout << "Maximum amount robbed: " << ans << endl;

    return 0;
}