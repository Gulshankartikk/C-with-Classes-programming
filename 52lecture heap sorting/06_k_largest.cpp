#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {

        vector<int> ans;

        // Min Heap
        priority_queue<int, vector<int>, greater<int>> p;

        // Insert first k elements
        for(int i = 0; i < k; i++) {
            p.push(arr[i]);
        }

        // Process remaining elements
        for(int i = k; i < arr.size(); i++) {

            if(p.top() < arr[i]) {
                p.pop();
                p.push(arr[i]);
            }
        }

        // Store answer
        while(!p.empty()) {
            ans.push_back(p.top());
            p.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    vector<int> arr = {1, 23, 12, 9, 30, 2, 50};
    int k = 3;

    Solution ob;

    vector<int> ans = ob.kLargest(arr, k);

    cout << "K largest elements are: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}