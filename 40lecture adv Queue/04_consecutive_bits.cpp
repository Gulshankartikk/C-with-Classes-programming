#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n= nums.size();
        int flips =0;
        queue<int> q;

        for(int i=0;i<n;i++){
            if(!q.empty()&&q.front()==i-k)
                q.pop();

            if(q.size()%2 == nums[i]){
                if(i+k>n)
                    return -1;
                
                flips++;
                q.push(i);
            }
        }
        return flips;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {0,1,0}; // example input
    int k = 1;

    int result = obj.minKBitFlips(nums, k);

    cout << "Minimum K bit flips: " << result << endl;

    return 0;
}