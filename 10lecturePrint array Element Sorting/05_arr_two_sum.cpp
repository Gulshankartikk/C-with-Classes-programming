#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums = {2,3,8,7,4};
    int target = 10;

    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == target - nums[i]) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }

    return 0;
}