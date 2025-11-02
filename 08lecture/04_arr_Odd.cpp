#include<iostream>
using namespace std;

int main()
{
   
    int arr [8] = {2,3,7,-11,12,8,13};
    for(int i=0; i<=8 ;i++)
    {
        if(arr[i]%2==1||arr[i]%2==-1)
        cout<<arr[i]<<" ";
    }
    return 0;
}