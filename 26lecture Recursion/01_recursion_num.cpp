#include<iostream>
using namespace std;

void print_number(int start,int end)
{
    if(start>end)
    return;

    cout<<start<<" ";
    print_number(start+1,end);
}

int main()
{
    int n =20;
    print_number(1,20);
    return 0;
}