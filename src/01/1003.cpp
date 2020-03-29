#include <iostream>

using namespace std;

unsigned long long array[40] = {0};
int a = 0;
int b = 0;

int pibonacci(int n) {
    if (n == 0) {
        a++;
        return 0;
    } else if (n == 1) {
        b++;
        return 1;
    } else {
        return pibonacci(n - 1) + pibonacci(n - 2);
    }
}

unsigned long long fibonacci(int n) {
    if (n == 0) {
        a++;
        return 0;
    }
    if (n == 1) {
        b++;
        return 1;
    }
    if (n - 1 == 0 || n - 2 == 0) a++;
    if (n - 1 == 1 || n - 2 == 1) b++;
    if (array[n] != 0) {
        return array[n];
    }
    array[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return array[n];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        a = 0;
        b = 0;

        fibonacci(n);
        cout << a << " " << b << endl;
    }
}