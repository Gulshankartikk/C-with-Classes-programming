#include<iostream>
using namespace std;

class Student
{
    public:
    int roll;
    string Name;
    string Branch;
};

int main()
{
    Student object;
    object.roll =123;
    object.Name = "Rahul";
    object.Branch = "CSE";
    cout << object.roll <<" ";
    return 0;
}