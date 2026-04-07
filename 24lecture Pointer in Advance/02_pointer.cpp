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
   cout<<arr<<endl;//address of first element in an array
   cout<<&arr<<endl;//memory location of array
   cout<<&arr[0]<<endl;//address of first element in array
   cout<<&arr[1]<<endl;//address of second element in array
   cout<<&arr[2]<<endl;
    return 0;
}