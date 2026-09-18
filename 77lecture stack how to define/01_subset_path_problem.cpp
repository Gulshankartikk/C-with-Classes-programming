#include <iostream>
#include <vector>
using namespace std;

bool findSubset(int n, int sum, vector<int>& arr) {
    if (sum == 0)
        return true;

    if (n == 0)
        return false;

    if (sum < arr[n - 1])
        return findSubset(n - 1, sum, arr);

    return findSubset(n - 1, sum - arr[n - 1], arr) ||
           findSubset(n - 1, sum, arr);
}

int main() {
    int n, sum;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> sum;

    cout << (findSubset(n, sum, arr) ? "true" : "false") << endl;
    return 0;
}

/*#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < arr[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> sum;

    cout << (isSubsetSum(arr, sum) ? "true" : "false") << endl;
    return 0;
}*/