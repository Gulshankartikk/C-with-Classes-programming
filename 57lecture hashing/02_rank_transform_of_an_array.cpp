#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    // Copy the original array
    vector<int> temp = arr;

    // Sort the copied array
    sort(temp.begin(), temp.end());

    // Store rank of each unique element
    unordered_map<int, int> rank;
    int r = 1;

    for (int num : temp) {
        if (rank.find(num) == rank.end()) {
            rank[num] = r++;
        }
    }

    // Replace each element with its rank
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rank[arr[i]];
    }

    return arr;
}

int main() {
    vector<int> arr = {40, 10, 20, 30};

    vector<int> ans = arrayRankTransform(arr);

    cout << "Rank Transformed Array: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}