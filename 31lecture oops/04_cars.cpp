#include<iostream>
using namespace std;

class car
{
    int cost;
    int mileage;
    public:
    car(int cost,int mileage)
    {
        this->cost=    cost;
        this->mileage=mileage;
        cout<<"hello constructor";
    };
    void print(){
        cout<<"cost"<<" "<<mileage;
    }
};

int main()
{
    car obj(20,10);
    obj.print();
    return 0;
}