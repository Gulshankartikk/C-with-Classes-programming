#include<iostream>
using namespace std;

void fun(int **x,int row,int col)
{
    for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
    x[i][j] = i+j;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int **p = new int*[n];
    for(int i=0;i<n;i++) 
    p[i] = new int [m];

    fun (p,n,m);
    return 0;
}