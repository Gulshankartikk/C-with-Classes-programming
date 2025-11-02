#include<iostream>
using namespace std;

int main()
{
    int arr[5] = {2,3,8,7,4};

    for(int i=0;i<5;i++)
    {
        for(int j=4-i;j>=0;j--)
        cout<<arr[j]<<" ";

        cout<<endl;
    }
    return 0;
}


// output

// 4 7 8 3 2 
// 7 8 3 2 
// 8 3 2 
// 3 2 
// 2