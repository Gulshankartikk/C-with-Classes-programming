
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        
        int n = gas.size();
        
        int front = 0, rear = 0;
        int tank = 0;
        
        while (front < n) {
            
            tank += gas[rear] - cost[rear];
            
            if (tank < 0) {
                if (rear < front)
                    return -1;
                
                tank = 0;
                front = rear + 1;
                rear = front;
            } 
            else {
                rear = (rear + 1) % n;
                
                if (front == rear)
                    return front;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution obj;
    
    int n;
    cin >> n;
    
    vector<int> gas(n), cost(n);
    
    for (int i = 0; i < n; i++)
        cin >> gas[i];
    
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    
    int result = obj.startStation(gas, cost);
    
    cout << result << endl;
    
    return 0;
}