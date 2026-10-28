#include <iostream>
#include <vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return arr;

    int rmax = arr[n - 1];
    arr[n - 1] = -1;

    for (int i = n - 2; i >= 0; i--) {
        int tmp = arr[i];
        arr[i] = rmax;
        if (rmax < tmp)
            rmax = tmp;
    }
    return arr;
}

int main() {
    vector<int> arr = {17, 18, 5, 4, 6, 1};

    replaceElements(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}