#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    double median;

    void insertHeap(int &x)
    {
        if(max.empty() && min.empty())
        {
            median = x;
            max.push(x);
            return;
        }

        if(x <= median)
            max.push(x);
        else
            min.push(x);
    }

    void balanceHeaps()
    {
        if(abs((int)max.size() - (int)min.size()) > 1)
        {
            if(max.size() > min.size())
            {
                min.push(max.top());
                max.pop();
            }
            else
            {
                max.push(min.top());
                min.pop();
            }
        }
    }

    vector<double> getMedian(vector<int> &arr)
    {
        vector<double> ans;

        if(max.size() == min.size())
        {
            median = (max.top() + min.top()) / 2.0;
        }
        else if(max.size() > min.size())
        {
            median = max.top();
        }
        else
        {
            median = min.top();
        }

        ans.push_back(median);
        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> arr = {5, 15, 1, 3};

    for(int x : arr)
    {
        obj.insertHeap(x);
        obj.balanceHeaps();

        vector<double> med = obj.getMedian(arr);

        cout << med[0] << " ";
    }

    return 0;
}