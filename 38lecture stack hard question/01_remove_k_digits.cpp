#include <iostream>
#include <stack>
#include <vector>  
#include <algorithm>   // for reverse
using namespace std;

class Solution {
  public:
    string removeKdig(string &s, int k) {
        
        stack<int> st;
        int i = 0, num;
        
        while(i < s.size())
        {
            num = s[i] - '0';
            while(st.size() && st.top() > num && k)
            {
                st.pop();
                k--;
            }
            st.push(num);
            i++;
        }
        
        while(k-- && st.size())
            st.pop();
        
        string ans;
        char c;
        
        while(st.size())
        {
            c = '0' + st.top();
            st.pop();
            ans += c;
        }
        
        i = ans.size() - 1;
        while(i >= 0 && ans[i] == '0')
        {
            ans.pop_back();
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans.size() == 0)
            return "0";
        else
            return ans;
    }
};

int main() {
    Solution obj;
    
    string s;
    int k;
    
    cout << "Enter number string: ";
    cin >> s;
    
    cout << "Enter k: ";
    cin >> k;
    
    string result = obj.removeKdig(s, k);
    
    cout << "Result: " << result << endl;
    
    return 0;
}