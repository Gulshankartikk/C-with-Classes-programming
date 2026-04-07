#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string S;
    cout << "Enter a string: ";
    cin >> S;

    vector<int> freq(26, 0);
    int first = 0, second = 0;
    int ans = 0;

    while (second < S.size()) {
        if (freq[S[second] - 'a'] == 0) {
            freq[S[second] - 'a'] = 1;
            ans = max(ans, second - first + 1);
            second++;
        } 
        else {
            freq[S[first] - 'a'] = 0;
            first++;
        }
    }

    cout << "Longest Unique Substring Length: " << ans << endl;
    return 0;
}
