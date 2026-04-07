#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (s1.size() != s2.size()) {
        cout << "Not anagrams (different lengths)." << endl;
        return 0;
    }

    int freq[256] = {0}; // Assuming ASCII character set

    for (char c : s1) {
        freq[c]++;
    }

    for (char c : s2) {
        freq[c]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            cout << "Not anagrams." << endl;
            return 0;
        }
    }

    cout << "The strings are anagrams!" << endl;
    return 0;
    
}