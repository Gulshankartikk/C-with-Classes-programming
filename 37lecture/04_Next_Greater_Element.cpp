#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> s;
        vector<int> ans(n);
        
        int i = 0;
        
        while(i < n)
        {
            if(s.size() == 0)
                s.push(i);
            else
            {
                if(arr[s.top()] >= arr[i])
                    s.push(i);
                else
                {
                    while(s.size() && arr[s.top()] < arr[i])
                    {
                        ans[s.top()] = arr[i];
                        s.pop();
                    }
                    s.push(i);
                }
            }
            i++;
        }
        
        while(s.size())
        {
            ans[s.top()] = -1;
            s.pop();
        }
        
        return ans;
    }
};

int main() {
    vector<int> arr = {4, 5, 2, 10};
    
    Solution obj;
    vector<int> result = obj.nextLargerElement(arr);
    
    cout << "Next Greater Elements:\n";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}