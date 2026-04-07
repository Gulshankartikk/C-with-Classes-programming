#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 1; i <= 10; i++)
        v.push_back(i * 13 % 10);

    sort(v.begin(), v.end());

    // Print using index
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // Print using range-based for loop
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
