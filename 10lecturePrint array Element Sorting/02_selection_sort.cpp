#include <iostream>
using namespace std;

int main()
{
    int arr[] = {64, 25, 12, 22, 11}; // ✅ array initialization
    int n = sizeof(arr) / sizeof(arr[0]); // ✅ size of array

    // Selection sort
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++) // ✅ start from i+1
        {
            if (arr[j] < arr[index])
                index = j;
        }

        // ✅ swap arr[i] and arr[index]
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }

    // ✅ print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
 