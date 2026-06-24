#include <iostream>
using namespace std;

int main() {
    int m = 3;  // number of subarrays (example)
    int arr[] = {10,15,10,20};  // input array
    int n = sizeof(arr) / sizeof(arr[0]);

    if (m > n) {
        cout << -1;
        return 0;
    }

    int start = arr[0], end = 0;
    for (int i = 0; i < n; i++) {
        end += arr[i];
        if (start < arr[i])
            start = arr[i];
    }

    int ans = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        int sum = 0, count = 1;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }

        if (count <= m) {
            ans = mid;       // possible answer
            end = mid - 1;   // try to find smaller max sum
        } else {
            start = mid + 1;
        }
    }

    cout << "Minimum maximum sum for " << m << " subarrays: " << ans << endl;

    return 0;
}
