#include<iostream>
using namespace std;

void fun(int &c, int&d)
{
   int temp =c;
   c=d;
   d=temp;
}

int main()
{
    int a=5,b=8;
    fun(a,b);
    cout<<a<<" "<<b;
    return 0;
}