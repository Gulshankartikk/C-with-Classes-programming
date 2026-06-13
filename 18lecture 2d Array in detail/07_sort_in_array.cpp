#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right])
            temp.push_back(nums[left++]);
        else
            temp.push_back(nums[right++]);
    }

    while (left <= mid)
        temp.push_back(nums[left++]);

    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);

    merge(nums, low, mid, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    mergeSort(nums, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}