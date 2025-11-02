#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 1, 2, 2, 3, 4, 4}; // sample array
    int n = sizeof(a) / sizeof(a[0]);

    int note = a[0];
    int index = 1; // first element is always unique

    for (int i = 1; i < n; i++) {
        if (note != a[i]) { // no semicolon here!
            note = a[i];
            index++; // found a new unique element
        }
    }

    cout << "Number of unique elements: " << index << endl;
    return 0;
}
