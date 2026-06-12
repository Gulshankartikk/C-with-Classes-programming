#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int> m;
        int distinct_count = 0;

        for(int i = 0; i < k; i++) {
            m[arr[i]]++;
            if(m[arr[i]] == 1)
                distinct_count++;
        }

        vector<int> ans;
        ans.push_back(distinct_count);

        for(int i = k; i < arr.size(); i++) {
            m[arr[i-k]]--;
            if(m[arr[i-k]] == 0)
                distinct_count--;

            m[arr[i]]++;
            if(m[arr[i]] == 1)
                distinct_count++;

            ans.push_back(distinct_count);
        }

        return ans;
    }
};

int main() {
    int n, k;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    Solution obj;
    vector<int> result = obj.countDistinct(arr, k);

    cout << "Distinct count in each window: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
} 