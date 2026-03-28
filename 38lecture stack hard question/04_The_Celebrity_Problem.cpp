#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& M) {
        int n = M.size();
        
        stack<int> s;
        for(int i = 0; i < n; i++)
            s.push(i);
            
        int first, second;
        
        while(s.size() > 1)
        {
            first = s.top();
            s.pop();
            second = s.top();
            s.pop();
            
            if(M[first][second])
                s.push(second);
            else
                s.push(first);
        }
        
        if(s.size() == 0)
            return -1;
        
        int check = s.top();
        int count_row = 0, count_col = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i == check) continue;
            
            count_col += M[i][check];
            count_row += M[check][i];
        }
        
        if(count_row == 0 && count_col == n-1)
            return check;
        else
            return -1;
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> M(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }
    
    Solution obj;
    cout << obj.celebrity(M) << endl;
    
    return 0;
}