#include<iostream>
using namespace std;

int main()
{
   
    int arr [8] = {2,3,7,1,-11,12,8,13};

    int num = arr[7];

    for(int i=6; i>=0 ;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]= num;

    for(int i=0;i<8;i++)
    cout<<arr[i]<<" ";
    return 0;
}