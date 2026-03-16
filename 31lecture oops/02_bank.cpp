#include<iostream>
using namespace std;

class bank
{
    public:
    int balance;
    string Name;
    void check_balance()
    {
        cout<<balance<<" ";
    }
    void withdraw()
    {
        balance-=100;
        cout<<"100 rs nikal liye";
    };
};

int main()
{
    bank obj;
    obj.balance = 1000;
    obj.Name = "Rahul";
    obj.check_balance();
    obj.withdraw();
    obj.check_balance();

} 