#include<iostream>
using namespace std;
int IsEvenOdd(int name)  //function declare
{
    if(name%2==0)         //function defined
    return 0;
    else
    return 1;
}
int main()
{
    int num;
    cin>>num;
    int n = IsEvenOdd(num); //function call
    if(n==0)
    cout<<"even";
    else
    cout<<"odd";
    return 0;
}
