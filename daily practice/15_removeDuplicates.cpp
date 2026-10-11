#include <iostream>
#include <vector>
using namespace std;

vector<int> removeDuplicates(vector<int> &arr) {
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            res.push_back(arr[i]);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 3, 4};

    vector<int> result = removeDuplicates(arr);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}