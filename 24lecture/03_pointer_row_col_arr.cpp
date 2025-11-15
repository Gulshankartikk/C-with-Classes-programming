#include<iostream>
using namespace std;

void fun1(int a[][4],int row ,int col)
{
    int count =0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<=col;j++)
        {
            a[i][j]=count;
        }
    };
}
int main()
{
    int arr[3][4];
    fun1(arr,3,4);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        // cout<<endl;
    }
    return 0;
}