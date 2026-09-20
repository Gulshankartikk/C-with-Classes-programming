#include <bits/stdc++.h>
using namespace std;

int find(int eggs, int floors, vector<vector<int>>& dp) {
    if (floors == 0 || floors == 1)
        return floors;

    if (eggs == 1)
        return floors;

    if (dp[eggs][floors] != -1)
        return dp[eggs][floors];

    int low = 1, high = floors;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int eggBreaks = find(eggs - 1, mid - 1, dp);
        int eggSurvives = find(eggs, floors - mid, dp);

        int temp = 1 + max(eggBreaks, eggSurvives);
        ans = min(ans, temp);

        if (eggBreaks > eggSurvives)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return dp[eggs][floors] = ans;
}

int main() {
    int eggs = 2;
    int floors = 10;

    vector<vector<int>> dp(
        eggs + 1, vector<int>(floors + 1, -1)
    );

    cout << find(eggs, floors, dp);

    return 0;
}



/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int eggs = 2;
    int floors = 10;

    vector<vector<int>> dp(
        eggs + 1, vector<int>(floors + 1, 0)
    );

    // Base case: one egg
    for (int f = 0; f <= floors; f++) {
        dp[1][f] = f;
    }

    for (int e = 2; e <= eggs; e++) {
        for (int f = 1; f <= floors; f++) {
            int low = 1, high = f;
            int ans = INT_MAX;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int eggBreaks = dp[e - 1][mid - 1];
                int eggSurvives = dp[e][f - mid];

                int temp = 1 + max(eggBreaks, eggSurvives);
                ans = min(ans, temp);

                if (eggBreaks > eggSurvives)
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            dp[e][f] = ans;
        }
    }

    cout << dp[eggs][floors];

    return 0;
}*/