#include <iostream>
#include <algorithm>

using namespace std;

int *factorials;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    if (factorials[n] != 0) return factorials[n];

    factorials[n] = n * factorial(n - 1);
    return factorials[n];
}

int main_() {
    int n, k;
    cin >> n >> k;

    factorials = new int[n + 1];
    fill(factorials, factorials + n + 1, 0);

    for (int i = 0; i < n; i++) {
        factorial(i);
    }

    cout << factorial(n) / (factorial(n - k) * factorial(k)) << endl;

    delete[] factorials;

    return 0;
}