#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        // Step 1: Extract words
        for (char c : s) {
            if (c == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp = "";
                }
            } else {
                temp += c;
            }
        }

        // Add last word
        if (!temp.empty()) {
            words.push_back(temp);
        }

        // Step 2: Reverse words
        reverse(words.begin(), words.end());

        // Step 3: Join with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1)
                result += " ";
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    getline(cin, s);   // allows spaces in input

    string result = obj.reverseWords(s);

    cout << "Reversed words: " << result << endl;

    return 0;
}