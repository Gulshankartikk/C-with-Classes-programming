#include <iostream>
#include <algorithm>
using namespace std;

string processStr(string s) {
    string result = "";

    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            result += ch;
        }
        else if (ch == '*') {
            if (!result.empty()) {
                result.pop_back();
            }
        }
        else if (ch == '#') {
            result += result;
        }
        else if (ch == '%') {
            reverse(result.begin(), result.end());
        }
    }

    return result;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    string output = processStr(s);
    cout << "Output: " << output << endl;

    return 0;
}