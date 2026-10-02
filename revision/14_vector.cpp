#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "enter array size :";
    cin >> n;
    // int arr[n];
    vector<int> arr(n,8);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}