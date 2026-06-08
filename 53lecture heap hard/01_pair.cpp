#include<iostream>
#include<vector>
using namespace std;

int main()
{
    pair<int, pair<int, int>> p;

    p = make_pair(10, make_pair(20, 30));

    cout << p.first << " "
         << p.second.first << " "
         << p.second.second;

    return 0;
}