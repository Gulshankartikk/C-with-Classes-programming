#include <iostream>
using namespace std;

int main() {
    int nums[10] = {2, 3, 6, 24, 45, 65, 65, 74, 74, 75}; 
    int target = 6;

    int n = sizeof(nums) / sizeof(nums[0]); // size of array
    int start = 0, end = n - 1, mid;
    int index = -1; // default if target not found

    while (start <= end) {
        mid = (start + end) / 2;
        if (nums[mid] == target) {
            index = mid;
            break; // target found
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}
