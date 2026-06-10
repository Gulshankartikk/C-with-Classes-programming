#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstElement(vector<int>& arr, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (m[arr[i]] == k)
                return arr[i];
        }

        return -1;
    }
};

int main() {
    vector<int> arr = {1, 7, 4, 3, 4, 8, 7};
    int k = 2;

    Solution obj;
    cout << obj.firstElement(arr, k) << endl;

    return 0;
}