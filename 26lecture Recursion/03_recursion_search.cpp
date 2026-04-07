#include<iostream>
using namespace std;

int search(int *a,int size,int key)
{
    if(size==0)
    return 0;

    if(a[0]==key)
    return 1;

    return search(a+1,size-1,key);
}
int main() 
{
    int arr[6] ={2,4,21,8,9,12};
    int key =2;
    cout<<search(arr,6,key);
    return 0;
}