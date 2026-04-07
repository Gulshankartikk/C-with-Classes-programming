#include<iostream>
using namespace std;
///wrong solution  fixed it

void merge(int arr[], int l, int mid, int r) {
        int n = r - l + 1;
        int* temp = new int[n];

        int i = l;        // left subarray pointer
        int j = mid + 1;  // right subarray pointer
        int k = 0;        // temp array pointer

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];   // ✅ fixed
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= r)
            temp[k++] = arr[j++];

        // Copy back to original array
        for (int p = 0; p < n; p++)
            arr[l + p] = temp[p];

        delete[] temp;
    }

    void mergeSort(int arr[], int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }



/*void merge(int arr[],int l,int m,int r)
{
    int*ans =new int [r-l+1];
    int first =l,second=m+1,pos=0;
    while(first<=m && second<=r)
    {
        if(arr[first]<=arr[second])
        ans[pos++] =arr[first++];
        else
        ans[pos++ ]= arr[first++];
    } 
    while(first<=m)
    ans[pos++]=arr[first++];
    while(second<=r)
    ans[pos++]=arr[second++];
    pos=0,m=l;
    while(m<=r)
    arr[m++]=ans[pos++];
    delete[]ans;
}

void mergesort(int arr[],int l,int r)
{
    if(l==r)
    return;
    int mid =l+(r-l)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
    */