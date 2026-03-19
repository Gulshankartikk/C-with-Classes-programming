#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 25, 12, 22, 11}; // ✅ array initialization
    int n = sizeof(arr) / sizeof(arr[0]); // ✅ size of array

    // insertion sort
    for (int i = 0; i < n - 1; i++)
    {
         for(int j=i; j>=0;j--)
        {
            if(arr[j]>arr[j+1])
        
        {
           int temp =arr[j];
           arr[j] = arr[j+1];
          arr[j+1] = temp;
        }
            else
          break;
    }
    }
    // ✅ print sorted array
    cout << "insertion sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 