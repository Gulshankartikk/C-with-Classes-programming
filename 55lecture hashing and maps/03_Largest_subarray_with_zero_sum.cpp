#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& A) {
        int len = 0;
        unordered_map<int, int> m;
        int sum = 0;

        for (int i = 0; i < A.size(); i++) {
            sum += A[i];

            if (sum == 0)
                len = i + 1;

            if (m.count(sum))
                len = max(len, i - m[sum]);
            else
                m[sum] = i;
        }

        return len;
    }
};

int main() {
    vector<int> A = {15, -2, 2, -8, 1, 7, 10, 23};

    Solution obj;
    cout << "Length of largest subarray with sum 0: "
         << obj.maxLength(A) << endl;

    return 0;
}