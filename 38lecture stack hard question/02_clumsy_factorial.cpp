#include <iostream>
#include <stack>
#include <vector>  
#include <algorithm>
using namespace std;

class Solution {
public:
    int clumsy(int n) {
        stack<int> s;
        s.push(n);
        n--;
        
        int i = 0, num;
        
        while(n)
        {
            if(i == 0)
            {
                num = s.top(); s.pop();
                s.push(num * n);
            }
            else if(i == 1)
            {
                num = s.top(); s.pop();
                s.push(num / n);
            }
            else if(i == 2)
            {
                s.push(n);
            }
            else
            {
                s.push(-n);
            }
            
            i = (i + 1) % 4;
            n--;
        }
        
        int sum = 0;
        while(!s.empty())
        {
            sum += s.top();
            s.pop();
        }
        
        return sum;
    }
};

int main() {
    Solution obj;
    
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int result = obj.clumsy(n);
    
    cout << "Clumsy factorial: " << result << endl;
    
    return 0;
}