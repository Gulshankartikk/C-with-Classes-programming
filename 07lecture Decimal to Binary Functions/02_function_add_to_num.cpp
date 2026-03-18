#include<iostream>
using namespace std;

void add(int num1,int num2)
{
    cout<<num1+num2;
    return;
}
int main()
{
    int num1,num2;
    cin>>num1>>num2;  
    add(num1,num2);
    return 0;
}