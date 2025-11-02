#include<iostream>
using namespace std;

int main()
{
  int a=10,b=15,c=20;
  if(a>=b && a>=c)
  {
    cout<<a;
  }
  else if(b>=a && b>=c)
  {
    cout<<b;
  }
  else
  {
    cout<<c;
  }

}