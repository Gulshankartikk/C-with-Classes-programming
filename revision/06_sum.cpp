#include <iostream>
using namespace std;

int main()
{
 int arr[]={4,5,9,10,11,12,8,15,40,60};
 int n=sizeof(arr)/sizeof(arr[0]);
 int sum=0;
 for(int i=0;i<n;i++)
 {
    sum+=arr[i];
 }
 cout<<sum/n;
}
