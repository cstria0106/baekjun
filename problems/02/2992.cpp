#include <iostream>

using namespace std;

int main() {
    int x;
    int digits[6];

    cin >> x;

    int div = 100000;
    int base = x;
    for (int &digit : digits) {
        digit = base / div;
        base -= digit * div;
        div /= 10;
    }

}