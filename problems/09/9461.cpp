#include <iostream>

using namespace std;

unsigned int array[100] = {0};

unsigned int padovan(int n) {
    if (n == 0 || n == 1 || n == 2) return 1;
    if (n == 3 || n == 4) return 2;
    if (array[n] != 0) return array[n];

    array[n] = padovan(n - 1) + padovan(n - 5);
    return array[n];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << padovan(n - 1) << endl;
    }
}