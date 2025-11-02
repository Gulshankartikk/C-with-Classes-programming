#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n<2)
    {
     cout<<"not a prime";
     return 0;
    }
    for(int num=2; num<=n-1; num++){
        if (n%num  == 0)
        {
            cout<<"prime number"<<" ";
            return 0;
        }
        
    }
    cout<<"prime no";
    return 0;
}
