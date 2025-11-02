#include<iostream>
using namespace std;
int Factorial(int num)
{
    int fact =1;
    for(int i=1;i<=num;i++)
    fact = fact*i;
    return fact;
}
int main()
{
   int num;
   cin>>num;
   int ans = Factorial(num);
   cout<<ans;

    return 0;
}
