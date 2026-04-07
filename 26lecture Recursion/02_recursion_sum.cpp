#include<iostream>
using namespace std;

void print_sum(int*a,int sum,int size)
{
    if(!size)//size==0
    return;

    sum+=a[0];
    cout<<sum<<" ";
    print_sum(a+1,sum,size-1);
}

int main()
{
    int arr[6] ={2,4,21,8,9,12};
    int sum =0;

    print_sum(arr,sum,6);
    return 0;
}