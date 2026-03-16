#include<iostream>
using namespace std;

class car
{
    int cost;
    int mileage;
    public:
    car()
    {
        cost = 100000;
        mileage = 20;
        cout<<"hello constructor";
    };
};

int main()
{
    car obj;
    return 0;
}