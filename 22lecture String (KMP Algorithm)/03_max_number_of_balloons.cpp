#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxNumberOfBalloons(string text) {
    int b = 0, a = 0, l = 0, o = 0, n = 0;

    for (char ch : text) {
        if (ch == 'b') b++;
        else if (ch == 'a') a++;
        else if (ch == 'l') l++;
        else if (ch == 'o') o++;
        else if (ch == 'n') n++;
    }

    return min(min(b, a), min(min(l / 2, o / 2), n));
}

int main() {
    string text;
    cin >> text;

    cout << maxNumberOfBalloons(text) << endl;

    return 0;
}