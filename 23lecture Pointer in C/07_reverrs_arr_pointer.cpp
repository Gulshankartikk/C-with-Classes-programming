#include<iostream>
using namespace std;

void reverse(int *arr, int size)
{
    int start=0;
    int end=size-1;
    while(start<end)
    {
        int temp =arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++,end--;
    }
}

int main()
{
    int a[5]={10,20,30,40,50};
    reverse(a,5);
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";
    return 0;
}