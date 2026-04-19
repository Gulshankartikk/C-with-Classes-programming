#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int heapHeight(int n, int arr[]) {
        if (n == 1) return 1;
        
        int height = 0;
        while (n > 1) {
            n = n / 2;
            height++;
        }
        return height;
    }
};

int main() {
    int n;
    cin >> n;

    int arr[n];  // input array (heap)
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    int height = obj.heapHeight(n, arr);

    cout << height << endl;

    return 0;
}