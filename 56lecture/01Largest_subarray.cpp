#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxLen(vector<int> &arr) {
        int len = 0;
        unordered_map<int, int> m;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 1)
                sum++;
            else
                sum--;

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
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements (0s and 1s): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << "Maximum length of subarray with equal 0s and 1s: "
         << obj.maxLen(arr) << endl;

    return 0;
}