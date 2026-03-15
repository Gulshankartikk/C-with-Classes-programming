#include <iostream>
using namespace std;

bool sum_possible(int *arr,int size,int index,int sum,int target)
{
  if (index==size)
  {
    if(sum==target)
    {
        return 1;
    }
    else 
    return 0;
  }
  return sum_possible(arr,size,index+1,sum,target)
  ||sum_possible(arr,size,index+1,sum+arr[index],target);
  
}

int main()
{
int arr[5]={1,2,4,7,3};
int index=0,sum=0;
int target=25;
cout<<sum_possible(arr,5,index,sum,target);
return 0;
}