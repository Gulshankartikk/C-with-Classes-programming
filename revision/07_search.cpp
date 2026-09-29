#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 5, 9, 10, 11, 12, 8, 15, 40, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "enter target :";
    cin >> x;
     bool flag =false;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==x){
            flag=true;
            break;
        }
    }
    if(flag==true) cout<<x<<" is present";
    else cout<<x<<" is not present";


    /*for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            cout << x << "is present";
            break;
       */
}
