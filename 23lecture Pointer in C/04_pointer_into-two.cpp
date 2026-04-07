#include<iostream>
using namespace std;

void fun(int *c, int*d)
{
    *c =(*c)*2;
    *d =(*d)*2;
}

int main()
{
    int a=5,b=8;
    fun(&a,&b);
    cout<<a<<" "<<b;
    return 0;
}