#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    int count_zero = 0;
    int count_one = 0;
    int count_two = 0;

    // Count 0, 1 and 2
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            count_zero++;
        else if (arr[i] == 1)
            count_one++;
        else
            count_two++;
    }

    // Put 0s
    for (int i = 0; i < count_zero; i++)
    {
        arr[i] = 0;
    }

    // Put 1s
    for (int i = count_zero; i < count_zero + count_one; i++)
    {
        arr[i] = 1;
    }

    // Put 2s
    for (int i = count_zero + count_one; i < arr.size(); i++)
    {
        arr[i] = 2;
    }

    // Print array
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}