#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int N = strs.size();
    if (N == 0) return "";

    // Find length of the shortest string
    int M = INT_MAX;
    for(int i = 0; i < N; i++)
        M = min(M, (int)strs[i].size());

    int count = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 1; j < N; j++) {
            if(strs[j-1][i] != strs[j][i]) {
                if(count) return strs[0].substr(0, count);
                else return "";
            }
        }
        count++;
    }

    return strs[0].substr(0, count);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"}; // Example input

    string ans = longestCommonPrefix(strs);
    if(ans == "") cout << "-1";
    else cout << ans;

    return 0;
}
