#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void push_right(vector<int> &arr, int n, int right[]) {
        stack<int> s;
        int i = 0;
        
        while(i < n) {
            if(s.size() == 0)
                s.push(i);
            else {
                if(arr[i] >= arr[s.top()])
                    s.push(i);
                else {
                    while(s.size() && arr[i] < arr[s.top()]) {
                        right[s.top()] = i;
                        s.pop();   
                    }
                    s.push(i);
                }
            }
            i++;
        }
        while(s.size()) {
            right[s.top()] = n;
            s.pop();
        }
    }

    void push_left(vector<int> &arr, int n, int left[]) {
        stack<int> s;
        int i = n - 1;
        
        while(i >= 0) {
            if(s.size() == 0)
                s.push(i);
            else {
                if(arr[i] >= arr[s.top()])
                    s.push(i);
                else {
                    while(s.size() && arr[i] < arr[s.top()]) {
                        left[s.top()] = i;
                        s.pop();   
                    }
                    s.push(i);
                }
            }
            i--;
        }
        while(s.size()) {
            left[s.top()] = -1;
            s.pop();   
        }
    }

    int getMaxArea(vector<int> &arr) {
        int n = arr.size();   
        
        int *right = new int[n];
        int *left = new int[n];
        
        push_right(arr, n, right);
        push_left(arr, n, left);   
        
        long long area = 0, ans;   
        
        for(int i = 0; i < n; i++) {
            ans = right[i] - left[i] - 1;
            ans = ans * arr[i];
            area = max(area, ans);   
        }
        
        return area;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.getMaxArea(arr) << endl;

    return 0;
}