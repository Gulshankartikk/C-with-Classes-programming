/*
=====recursive approach=====

class Solution {
public:

    int find(int n, int m, string &s1, string &s2, int &ans)
    {
        // Base condition
        if (n == 0 || m == 0)
            return 0;

        int len = 0;

        if (s1[n - 1] == s2[m - 1])
        {
            len = 1 + find(n - 1, m - 1, s1, s2, ans);

            ans = max(ans, len);
        }

        // If characters don't match, substring breaks
        find(n - 1, m, s1, s2, ans);
        find(n, m - 1, s1, s2, ans);

        return len;
    }

    int longCommSubstr(string& s1, string& s2)
    {
        int n = s1.size();
        int m = s2.size();

        int ans = 0;

        find(n, m, s1, s2, ans);

        return ans;
    }
};*/


#include <bits/stdc++.h>
using namespace std;

int longCommSubstr(string& X, string& Y)
{
    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Find common substring length
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    // Find maximum length
    int maxLen = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

int main()
{
    string X, Y;

    cin >> X >> Y;

    cout << longCommSubstr(X, Y);

    return 0;
}

