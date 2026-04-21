#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 1};   // ✅ added

    unordered_set<int> numSet;

    for (int n : nums)
    {
        if (numSet.find(n) != numSet.end())
        {
            cout << "true";
            return 0;
        }
        numSet.insert(n);
    }

    cout << "false";
    return 0;
}