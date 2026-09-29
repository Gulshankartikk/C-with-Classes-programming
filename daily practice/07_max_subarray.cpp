#include <iostream>
#include <vector>
#include <algorithm>   // for max()
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current = max(nums[i], current + nums[i]);
        best = max(best, current);
    }
    return best;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Max subarray sum: " << result << endl;   // 6

    return 0;
}