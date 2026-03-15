#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    void solve(int index, vector<int>& arr, int target,
               vector<int>& temp, vector<vector<int>>& ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<arr.size();i++)
        {
            if(arr[i] > target)
                continue;

            temp.push_back(arr[i]);

            solve(i,arr,target-arr[i],temp,ans); // reuse same element

            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0,arr,target,temp,ans);

        return ans;
    }
};

int main()
{
    vector<int> arr = {2,3,6,7};
    int target = 7;

    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(arr,target);

    for(auto v:ans)
    {
        for(int x:v)
            cout<<x<<" ";
        cout<<endl;
    }
}