#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 5, 9, 10, 11, 12, 8, 15, 40, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mx = INT_MIN; 
    int mn =INT_MAX;
    for (int i = 0; i < n; i++)
    {
        //    if(mx<arr[i])mx=arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn,arr[i]);
    }
    cout << mx<<" "<<mn;
}
