#include<iostream>
using namespace std;
int main()
{
    int arr[3][4];
    for(int i=0;i<3;i++)
       for(int j=0;j<4;j++)
     cin>>arr[i][j];

     for(int j=0;j<4;j++){
         for(int i=0;i<3;i++)
            {
             cout<<arr[i][j]<<" ";
            }
            cout<<endl;
    }    
    return 0;
}