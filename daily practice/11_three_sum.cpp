#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        // Skip duplicate i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                ans.push_back({
                    nums[i],
                    nums[left],
                    nums[right]
                });

                left++;
                right--;

                // Skip duplicate left
                while (left < right &&
                       nums[left] == nums[left - 1])
                {
                    left++;
                }

                // Skip duplicate right
                while (left < right &&
                       nums[right] == nums[right + 1])
                {
                    right--;
                }
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    // Print answer
    for (auto triplet : ans)
    {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++)
        {
            cout << triplet[i];

            if (i < triplet.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}