#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int arr[6]={2,5,1,6,7,11};
    int size=6;
    int dp[size];
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(int i=2;i<size;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    cout<<dp[size-1];
}
