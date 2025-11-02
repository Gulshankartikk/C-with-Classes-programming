#include<iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   int num =10;
   int digit=1;
   for(int i=1;i>0;i++)
   {
    if(n/num==0)
    {
     cout<<digit;
     return 0;
    }
    num= num*10;
    digit++;
   }
    return 0;
}