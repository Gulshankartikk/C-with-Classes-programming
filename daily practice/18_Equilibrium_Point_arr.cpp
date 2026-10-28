#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 3, 5, 2, 2};
    int n = 5;

    for (int i = 0; i < n; i++) {
        int left = 0, right = 0;

        for (int j = 0; j < i; j++)
            left += a[j];

        for (int j = i + 1; j < n; j++)
            right += a[j];

        if (left == right) {
            cout << "Equilibrium index: " << i << endl;
            return 0;
        }
    }

    cout << "No equilibrium point" << endl;
    return 0;
}

/*class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        long long total = 0, left = 0;
        for (int x : arr) total += x;

        for (int i = 0; i < arr.size(); i++) {
            long long right = total - left - arr[i];
            if (left == right) return i;
            left += arr[i];
        }
        return -1;
    }
};*/