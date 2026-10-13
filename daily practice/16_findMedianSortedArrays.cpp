#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    int i = 0, j = 0;

    // merge two sorted arrays into one sorted array
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
        else merged.push_back(nums2[j++]);
    }
    while (i < nums1.size()) merged.push_back(nums1[i++]);
    while (j < nums2.size()) merged.push_back(nums2[j++]);

    int total = merged.size();
    if (total % 2 == 1) return merged[total / 2];
    return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
}

int main() {
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    vector<int> nums1(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> m;
    vector<int> nums2(m);
    cout << "Enter " << m << " sorted elements: ";
    for (int i = 0; i < m; i++) cin >> nums2[i];

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median = " << median << endl;

    return 0;
}

/*class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // always binary search on the smaller array
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size(), m = nums2.size();
        int low = 0, high = n;
        int half = (n + m + 1) / 2;   // size of the left part

        while (low <= high) {
            int i = (low + high) / 2;  // taken from nums1 into left part
            int j = half - i;          // taken from nums2 into left part

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == n) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == m) ? INT_MAX : nums2[j];

            if (l1 <= r2 && l2 <= r1) {          // correct split found
                if ((n + m) % 2 == 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) high = i - 1;      // took too many from nums1
            else low = i + 1;                    // took too few from nums1
        }
        return 0.0;
    }
};*/