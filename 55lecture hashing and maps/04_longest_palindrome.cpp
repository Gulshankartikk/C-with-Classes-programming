#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freq;

    // Count frequency
    for (char c : s) {
        freq[c]++;
    }

    int ans = 0;
    bool odd = false;

    for (auto it : freq) {
        if (it.second % 2 == 0) {
            ans += it.second;
        } else {
            ans += it.second - 1;
            odd = true;
        }
    }

    if (odd)
        ans++;

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;

    return 0;
}