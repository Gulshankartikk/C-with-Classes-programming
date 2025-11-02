#include<iostream>
using namespace std;
int main()
{
    int arr[7] = {1,2,2,3,1,3,13};
    int ans = 0;
    for(int i=0;i<7;i++)
    ans =ans^arr[i];

    cout<<ans;
    return 0;
}