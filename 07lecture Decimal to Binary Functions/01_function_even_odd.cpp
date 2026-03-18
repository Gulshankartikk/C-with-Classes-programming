#include<iostream>
using namespace std;
// method 1

// int IsEvenOdd(int num)
// {
//     if(num%2==0)
//     return 0;
//     else 
//     return 1;
// }
// int main()
// {
//    int num1,num2,num3;
//    cin>>num1>>num2>>num3;
//    int value = IsEvenOdd(num1);
//    if(value==0)
//    cout<<"even";
//    else
//    cout<<"odd";

//     return 0;
// }

// method 2
void IsEvenOdd(int num)
{
    if(num%2==0)
    cout<<"even"<<endl;
    else
    cout<<"odd"<<endl;

    return;
}
int main()
{
    int num1,num2,num3;
    cin>>num1>>num2>>num3;
    IsEvenOdd(num1);
    IsEvenOdd(num2);
    IsEvenOdd(num3);
    
    return 0;

}
   
