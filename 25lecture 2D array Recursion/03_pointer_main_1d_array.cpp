#include<iostream>
using namespace std;

void fun (int*a,int size)
{
    for (int i=0; i<size;i++)
    a[i]=i;
}

int main()
{
    int m;
    cin>>m;
    int*p =new int [m];
    fun(p,m);

    return 0;
}