#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        vector<int> ans;                
        queue<int> q;                   
        
        int n = arr.size();             
        
        for(int i = 0; i < k - 1; i++)  
        {
            if(arr[i] < 0)              
                q.push(i);
        }
        
        for(int i = k - 1; i < n; i++)  
        {
            if(arr[i] < 0)
                q.push(i);
            
            if(q.empty())
                ans.push_back(0);
            else
                ans.push_back(arr[q.front()]);  
            
            if((!q.empty()) && q.front() <= i - k + 1) 
                q.pop();
        }
        
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    Solution obj;
    vector<int> result = obj.firstNegInt(arr, k);
    
    for(int x : result)
        cout << x << " ";
    
    cout << endl;
    
    return 0;
}