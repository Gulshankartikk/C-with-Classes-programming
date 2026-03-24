#include <iostream>
using namespace std;

int main() {
    int m = 8;  // target
    int arr[] = {5, 7, 7, 8, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0, end = n - 1, first = -1, last = -1, mid;

    // Find first occurrence
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == m) {
            first = mid;
            end = mid - 1;  // move left to find first occurrence
        } else if (arr[mid] < m) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    // Find last occurrence
    start = 0;
    end = n - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == m) {
            last = mid;
            start = mid + 1;  // move right to find last occurrence
        } else if (arr[mid] < m) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << "First occurrence: " << first << endl;
    cout << "Last occurrence: " << last << endl;

    return 0;
}
