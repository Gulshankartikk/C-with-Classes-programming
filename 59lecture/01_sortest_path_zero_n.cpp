#include <iostream>
using namespace std;

int minimumStep(int n) {
    int count_edge = 0;

    while (n >= 3) {
        count_edge += n % 3;
        n /= 3;
        count_edge++;
    }

    count_edge += n;
    count_edge--;

    return count_edge; 
}

int main() {
    int n;
    cin >> n;

    cout << minimumStep(n) << endl;

    return 0;
}