#include <iostream>
using namespace std;
void reverse(int arr[],int i,int j)
{
    while(i<j)
    swap(arr[i],arr[j]);
    i++;
    j--;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / 4;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    reverse(arr,1,4);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


/*class Solution {
public:
void reverse(vector<int>& nums,int i,int j)
{
    while(i<j)
    {
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};*/