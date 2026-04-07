#include<iostream>
using namespace std;

int binary_search(int *a,int start,int end, int key){
    if(end<start)
    return 0;

    int mid = end+(start-end)/2;

    if(a[mid]==key)
    return 1;

    else if(a[mid]>key)
    return binary_search(a,start,mid-1,key);

    else
    return binary_search(a,mid+1,end, key);
}
int main(){
   int arr[10] = {2,4,5,7,8,19,23,25,29,90};
   int key =25 ;
   cout<<binary_search(arr,0,9,key);
   return 0;
}