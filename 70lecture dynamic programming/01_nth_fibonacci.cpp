#include <iostream>
#include <vector>
using namespace std;

int find(int n, vector<int>& dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = find(n - 1, dp) + find(n - 2, dp);

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << find(n, dp) << endl;

    return 0;
}

/*class Solution {
  public:
  
  
    int nthFibonacci(int n) {
        // code here
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        dp[i] =dp[i-1]+dp[i-2];
        return dp[n];
    }
};*/

/*class Solution {
  public:
  
  
    int nthFibonacci(int n) {
        // code here
       if(n<=1)
       return n;
       int first =0;
       int second =1;
       int third;
       
       for(int i=2;i<=n;i++)
       {
           third =first+second;
           first=second;
           second =third;
       }
       return third;
    }
};*/