#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {2, 3, 8, 7, 4};

    int n = arr.size();
    int i, max, min;

    if (n > 1) {
        if (arr[0] > arr[1]) {
            max = arr[0];
            min = arr[1];
        } else {
            min = arr[0];
            max = arr[1];
        }
        i = 2;
    } else {
        min = arr[0];
        max = arr[0];
        i = 1;
    }

    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > max) max = arr[i];
            if (arr[i + 1] < min) min = arr[i + 1];
        } else {
            if (arr[i + 1] > max) max = arr[i + 1];
            if (arr[i] < min) min = arr[i];
        }
        i += 2;
    }

    if (i == n - 1) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;

    return 0;
}