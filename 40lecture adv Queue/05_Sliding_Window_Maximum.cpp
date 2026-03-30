#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int x) {
        vector<int> v;
        if(nums.size() == 0)
            return v;

        deque<int> d;
        int i = 0, n = nums.size();

        for(i = 0; i < n && i < x; i++)
        {
            while(d.size() && nums[d.back()] < nums[i])
                d.pop_back();
            d.push_back(i);
        }

        v.push_back(nums[d.front()]);

        if(x >= nums.size())
            return v;

        for(int i = x; i < n; i++)
        {
            if((i - x) == d.front())
                d.pop_front();
            
            while(d.size() && nums[d.back()] < nums[i])
                d.pop_back();

            d.push_back(i);
            v.push_back(nums[d.front()]);
        }

        return v;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = obj.maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximum: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}