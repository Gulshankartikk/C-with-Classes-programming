#include <iostream>
using namespace std;

int main() {
    int nums[10] = {2, 3, 6, 24, 45, 65, 65, 74, 74, 75}; 
    int target = 6;
    int n = 10;
    
    int start = 0, end = n - 1;
    int left_index = -1, right_index = -1;

    // Find left index (first occurrence)
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            left_index = mid;
            end = mid - 1;  // move left
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    start = 0; end = n - 1;

    // Find right index (last occurrence)
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            right_index = mid;
            start = mid + 1;  // move right
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << "First occurrence: " << left_index << "\n";
    cout << "Last occurrence: " << right_index << "\n";

    return 0;
}
