#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number: ";
    cin >> x;

    if (x < 2) {
        cout << x << endl;
        return 0;
    }

    int start = 0, end = x, mid, ans;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (mid == x / mid) {
            ans = mid;
            break;
        } else if (mid < x / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << "Integer square root of " << x << " is " << ans << endl;
    return 0;
}
