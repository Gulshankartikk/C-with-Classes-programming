#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string& s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare after converting to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "abc";

    cout << boolalpha; // prints true/false instead of 1/0

    cout << "Input: " << s1 << endl;
    cout << "Output: " << obj.isPalindrome(s1) << endl << endl;

    cout << "Input: " << s2 << endl;
    cout << "Output: " << obj.isPalindrome(s2) << endl;

    return 0;
}