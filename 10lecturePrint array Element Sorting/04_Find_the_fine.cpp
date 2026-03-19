#include <iostream>
using namespace std;

// Function to calculate total fine
long long int totalFine(int date, int car[], int fine[], int n) {
    long long int collection = 0;

    if (date % 2 == 1) {
        // Odd date: sum all fines
        for (int i = 0; i < n; i++)
            collection += fine[i];
    } else {
        // Even date: sum fines of cars with odd numbers
        for (int i = 0; i < n; i++) {
            if (car[i] % 2 == 1)
                collection += fine[i];
        }
    }

    return collection;
}

int main() {
    int date;
    cout << "Enter date: ";
    cin >> date;

    int n;
    cout << "Enter number of cars: ";
    cin >> n;

    int car[n];   // array to store car numbers
    int fine[n];  // array to store fines

    // Input car numbers
    cout << "Enter car numbers: ";
    for (int i = 0; i < n; i++)
        cin >> car[i];

    // Input fines
    cout << "Enter corresponding fines: ";
    for (int i = 0; i < n; i++)
        cin >> fine[i];

    long long int collection = totalFine(date, car, fine, n);
    cout << "Total collection: " << collection << endl;

    return 0;
}
