#include<iostream>
#include<vector>
using namespace std;


bool sum_pos(int arr[],int size,int sum,int index,int total)
{
   if(index==size)
   {
    if(sum==total)
    return 1;
    else
    return 0;
   }

   return sum_pos(arr,size,sum,index+1,total)||sum_pos(arr,size,sum,index+1,total+arr[index]);

}

int main()
{
    int arr[6]={2,5,1,6,7,11};
    int sum=20;
    int total=0;
    cout<<sum_pos(arr,6,sum,0,total);
    return 0;
}