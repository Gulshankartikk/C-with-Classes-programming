#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 0, 1, 0, 1, 0};  // sample input

    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        if (arr[low] == 0) {
            low++;
        } else {
            swap(arr[low], arr[high]);
            high--;
        }
    }

    // print result
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}