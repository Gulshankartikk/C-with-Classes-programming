#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int insertposition = 0;

    // Pass 1: compact all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[insertposition] = nums[i];
            insertposition++;
        }
    }

    // Pass 2: fill the remaining positions with zeros
    while (insertposition < nums.size())
    {
        nums[insertposition++] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums) cout << x << " ";
}