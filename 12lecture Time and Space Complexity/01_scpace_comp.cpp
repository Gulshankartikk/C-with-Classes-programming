#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input size of array: ";
    cin >> n;

    int Input_array[n]; // ✅ declaring array of size n

    cout << "Enter the values in your array:\n";
    for (int i = 0; i < n; i++) {
        cin >> Input_array[i]; // ✅ input inside the loop
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
       arr[i] = Input_array[i]*10;
    }
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

    return 0;
}
