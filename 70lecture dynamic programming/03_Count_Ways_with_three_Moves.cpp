#include <iostream>
using namespace std;

long long find(int step, int n)
{
    if (step == n)
        return 1;

    if (step > n)
        return 0;

    return find(step + 1, n)
         + find(step + 2, n)
         + find(step + 3, n);
}

long long countWays(int n)
{
    return find(0, n);
}

int main()
{
    int n;
    cin >> n;

    cout << countWays(n) << endl;

    return 0;
}