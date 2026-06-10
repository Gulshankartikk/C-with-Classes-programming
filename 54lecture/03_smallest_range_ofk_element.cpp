#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        struct Node {
            int val;
            int row;
            int col;

            bool operator>(const Node& other) const {
                return val > other.val;
            }
        };

        priority_queue<Node, vector<Node>, greater<Node>> pq;

        int mx = INT_MIN;

        // Insert first element from each list
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }

        int start = 0, end = INT_MAX;

        while (pq.size() == nums.size()) {

            Node cur = pq.top();
            pq.pop();

            int mn = cur.val;

            if ((mx - mn < end - start) ||
                (mx - mn == end - start && mn < start)) {
                start = mn;
                end = mx;
            }

            int r = cur.row;
            int c = cur.col;

            if (c + 1 < nums[r].size()) {
                int nxt = nums[r][c + 1];

                pq.push({nxt, r, c + 1});
                mx = max(mx, nxt);
            }
        }

        return {start, end};
    }
};

int main() {
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    Solution obj;
    vector<int> ans = obj.smallestRange(nums);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}