#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;   // you MUST read s first

    int n = s.size();

    int LPS[n + 1];
    char str[n + 1];

    // Copy string into 1-based array and initialize LPS
    for(int i = 0; i < n; i++) {
        str[i + 1] = s[i];
        LPS[i] = 0;
    }
    LPS[n] = 0; // last value

    int first = 0, second = 2;

    while(second <= n) {
        if(str[first + 1] == str[second]) {
            LPS[second] = first + 1;
            first++, second++;
        } else {
            if(first == 0)
                second++;
            else
                first = LPS[first];
        }
    }

    cout << LPS[n];  // print result
    return 0;
}
