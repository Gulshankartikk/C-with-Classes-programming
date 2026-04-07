#include<iostream>
using namespace std;

int main(){
    int num =30;
    cout<<num<<endl;
    int *p;
    p=&num;

    *p=20;
    cout<<num;
    return 0;
}