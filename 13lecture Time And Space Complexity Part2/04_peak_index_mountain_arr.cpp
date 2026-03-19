#include <iostream>
using namespace std;

int searchInsert(int arr[], int n, int target) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2; // safer mid calculation
        if (arr[mid] == target)
            return mid;  // target found
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    // start now points to the correct insert position
    return start;
}

int main() {
    int arr[10] = {2, 3, 6, 24, 45, 65, 65, 74, 74, 75};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;

    int index = searchInsert(arr, n, target);
    cout << "Index to insert or found: " << index << endl;

    return 0;
}
