#include <iostream>
using namespace std;

int main() 
{
    long long A[] = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // example array
    int len = sizeof(A) / sizeof(A[0]);

    long long sum = 0;
    int first = 0, last = len - 1;

    while (first < last)
    {
        int length = last - first;
        long long height;
        if (A[first] > A[last])
            height = A[last--];
        else
            height = A[first++];

        long long area = length * height;
        if (area > sum)
            sum = area;
    }

    cout << "Maximum water area: " << sum << endl;

    return 0;
}
