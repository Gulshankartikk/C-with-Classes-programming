#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        while (left < right && !isalnum(s[right])) {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "abc";

    cout << boolalpha;

    cout << "Input: " << s1 << endl;
    cout << "Output: " << isPalindrome(s1) << endl << endl;

    cout << "Input: " << s2 << endl;
    cout << "Output: " << isPalindrome(s2) << endl;

    return 0;
}