#include <iostream>
#include <vector>
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = 0;

    for (int i = 0; i < n; i++)
    {
        actual += nums[i];
    }
    return expected - actual;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    int result = missingNumber(nums);
    cout << "missingNumber: " << result;
     return 0;
}