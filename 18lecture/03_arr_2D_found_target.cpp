#include<iostream>
using namespace std;
int main()
{
    int arr[3][4];
    for(int i=0;i<3;i++)
       for(int j=0;j<4;j++)
     cin>>arr[i][j];

     int target =10;

     for(int i=0;i<3;i++){
         for(int j=0;j<4;j++)
            {
                if(arr[i][j]==target)
                {
                    cout<<"found";
                    return 0;
                }
            }
           
    } 
    cout<<"not found";   
    return 0;
}