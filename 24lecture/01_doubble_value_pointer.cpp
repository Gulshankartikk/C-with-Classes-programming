#include<iostream>
using namespace std;

void Double_value(int a[],int size)
{
    for (int i=0;i<5;i++)
    {
        *a=*a*2;
        a++;
    }
}
int main()
{
    int arr[5] ={1,2,3,4,5};
    Double_value(arr,5);
    for(int i=0;i<5;i++)
    cout<<arr[i]<<" ";
    return 0;
}