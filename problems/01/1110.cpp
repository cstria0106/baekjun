#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int new_number = n;
    int cycle = 0;

    do {
        int a = new_number / 10;
        int b = new_number % 10;
        new_number = b * 10 + (a + b) % 10;
        cycle++;
    } while (new_number != n);

    cout << cycle;
}