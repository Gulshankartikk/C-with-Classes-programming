#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 2, 3, 5};
    int b[] = {2, 3, 4, 5, 6};

    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    int result[n + m];  // max possible size
    int k = 0;          // result array index

    int i = 0, j = 0;

    // Merge both arrays while removing duplicates
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            if (k == 0 || result[k - 1] != a[i]) {
                result[k++] = a[i];
            }
            i++;
        } else if (b[j] < a[i]) {
            if (k == 0 || result[k - 1] != b[j]) {
                result[k++] = b[j];
            }
            j++;
        } else {
            // both are equal
            if (k == 0 || result[k - 1] != a[i]) {
                result[k++] = a[i];
            }
            i++;
            j++;
        }
    }

    // Add remaining elements of a
    while (i < n) {
        if (k == 0 || result[k - 1] != a[i]) {
            result[k++] = a[i];
        }
        i++;
    }

    // Add remaining elements of b
    while (j < m) {
        if (k == 0 || result[k - 1] != b[j]) {
            result[k++] = b[j];
        }
        j++;
    }

    // Print result
    cout << "Union: ";
    for (int idx = 0; idx < k; idx++) {
        cout << result[idx] << " ";
    }
    cout << endl;

    return 0;
}
