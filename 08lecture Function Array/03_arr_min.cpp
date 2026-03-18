#include<iostream>
using namespace std;

int main()
{
   
    int arr [6] = {6,-5,3,11,-2,7};
    int smallest =arr[0];
    for(int i=1; i<6;i++)
    {
        if(arr[i]<smallest)
        smallest = arr[i];
    }
    cout<<smallest;
    return 0;
}