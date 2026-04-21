#include<iostream>
using namespace std;

int main()
{
    int arr[8] = {2,3,7,1,-11,12,8,13};

    int n = 8;   // ✅ added

    int last = arr[n-1];
    for(int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = last;

    return 0;
}