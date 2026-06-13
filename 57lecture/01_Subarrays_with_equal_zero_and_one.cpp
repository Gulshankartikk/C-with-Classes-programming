#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long int countSubarray(vector<int>& arr) {
    int n = arr.size();

    int sum = 0;
    long long int final = 0;
    unordered_map<int, int> m;

    m[0] = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)
            sum++;
        else
            sum--;

        final += m[sum];
        m[sum]++;
    }

    return final;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubarray(arr) << endl;

    return 0;
}