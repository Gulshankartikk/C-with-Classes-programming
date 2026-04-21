#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int cost =0;
        priority_queue<int,vector<int>, greater<int> >p;
        for(int i=0;i<arr.size();i++)
            p.push(arr[i]);
        
        int first ,second;
        while(p.size()!=1)
        {
            first =p.top();
            p.pop();
            second =p.top();
            p.pop();
            first+=second;
            cost+=first;
            p.push(first);
        }
        return cost;
    }
};

int main() {
    vector<int> arr = {4, 3, 2, 6};  // sample input
    Solution obj;

    int result = obj.minCost(arr);
    cout << "  = " << result << endl;

    return 0;
}