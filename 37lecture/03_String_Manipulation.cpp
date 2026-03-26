#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        stack<string> s;
        int i=0;
        while(i<arr.size())
        {
            if(s.size()==0)
            s.push(arr[i]);
            else{
                if(s.top()==arr[i])
                s.pop();
                else
                s.push(arr[i]);
            }
            i++;
        }
        return s.size();
    }
};

int main() {
    vector<string> arr = {"ab", "aa", "aa", "bcd", "ab"};

    Solution obj;
    int result = obj.removeConsecutiveSame(arr);

    cout << "Result: " << result << endl;

    return 0;
}