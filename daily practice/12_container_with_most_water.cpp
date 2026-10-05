#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int ans = 0;

    while (left < right) {
        int area = min(height[left], height[right]) * (right - left);
        ans = max(ans, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(arr) << endl;

    return 0;
}