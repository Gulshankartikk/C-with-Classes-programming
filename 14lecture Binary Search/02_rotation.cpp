#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};  // rotated sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    int start = 0, end = n - 1;
    int index = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            index = mid;
            break;
        }

        // Left half is sorted
        if (arr[start] <= arr[mid]) {
            if (key >= arr[start] && key < arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Right half is sorted
        else {
            if (key > arr[mid] && key <= arr[end])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
