#include<iostream>
using namespace std;

int  main()
{
    int x=5;
    int*p=&x;
    cout<<x<<endl;//x value
    cout<<&x<<endl;// x address
    cout<<p<<endl;//x address
    cout<<*p<<endl;//x value
    cout<<&p<<endl; //p address
    
    
    return 0;
}