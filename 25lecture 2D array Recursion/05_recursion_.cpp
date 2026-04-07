#include<iostream>
using namespace std;

int power(int n)
{
    if(n==1)
    return 3;
    return 3*power(n-1);
}

int main()
{
    int n;
    cin>>n;
    cout<<power(n);
    return 0;
}
