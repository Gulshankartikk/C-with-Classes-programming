#include <iostream>
#include <string>
using namespace std;

int findNthDigit(int n) {
    long long len = 1;      // digits in current numbers
    long long cnt = 9;      // count of numbers with 'len' digits
    long long start = 1;    // first number of current block

    // Find the block containing the nth digit
    while (n > len * cnt) {
        n -= len * cnt;
        len++;
        cnt *= 10;
        start *= 10;
    }

    // Find the actual number
    long long num = start + (n - 1) / len;

    // Convert to string and get the digit
    string s = to_string(num);

    return s[(n - 1) % len] - '0';
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Nth digit is: " << findNthDigit(n);

    return 0;
}