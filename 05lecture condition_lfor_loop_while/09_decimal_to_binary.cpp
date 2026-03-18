#include<iostream>
using namespace std;

int main()
{
   int num;
   cin>>num;
   int sum = 0;

   while(num){
    int digit = num%2;
    num =num/2;
    sum =sum*10+digit;
   }
 
   while(num){
     int digit = num%10;
    sum = sum *10+digit;
    num = num/10;
   }
   cout<<sum;
  
   
    return 0;
}