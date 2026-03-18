#include<iostream>
using namespace std;
// table print
//even or odd
//factorial
//prime or not
// 1 to number

void Table (int num)
{
    for(int i=1;i<=10;i++)
    cout<<num*i<<" ";
    return;
}

void IsEvenOdd(int num)
{
    if(num%2==0)
    cout<<"even"<<endl;
    else
    cout<<"odd"<<endl;

    return;
}
int Factorial(int num)
{
    int fact =1;
    for(int i=1;i<=num;i++)
    fact = fact*i;
    cout<<fact;
    return fact;
}



void prints(int num)
{
    for(int i=1;i<=10;i++)
    cout<<i<<" ";
}

int main()
{
    int num;
    cin>>num;
    Table(num);
    IsEvenOdd(num);
    Factorial(num);
    prints(num);
}
  
