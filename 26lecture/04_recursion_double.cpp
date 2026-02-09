#include<iostream>
using namespace std;

void Double_value(int *a,int size)
{
    if(!size)
    return;

    a[0]*=2; //a[0]=a[0]*2
    Double_value(a+1,size-1);
}

int main()
{
    int arr[6] ={2,4,21,8,9,12};
    Double_value(arr,6);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
    return 0;
}
