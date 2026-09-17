#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    if (n == 0)
        return 0;

    int size = 0;
    int start, end, mid, index;

    vector<int> LIS(n);

    LIS[0] = nums[0];

    for (int i = 1; i < n; i++) {

        start = 0;
        end = size;
        index = size + 1;

        while (start <= end) {

            mid = start + (end - start) / 2;

            if (LIS[mid] < nums[i]) {
                start = mid + 1;
            }
            else {
                index = mid;
                end = mid - 1;
            }
        }

        LIS[index] = nums[i];

        size = max(size, index);
    }

    return size + 1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Length of LIS: " << lengthOfLIS(nums) << endl;

    return 0;
}