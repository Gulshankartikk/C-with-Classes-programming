#include<iostream>
using namespace std;

int main()
{
    int *p = new int [10];
    for (int i=0;i<10;i++)
    {
        *p =*p*2;
        p++;
    }

    for(int i=0;i<10;i++)
    {
        --p;
        cout<<*p<<" ";
    }
    return 0;
}