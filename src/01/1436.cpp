#include <iostream>
#include <string>

using namespace std;

bool is_end_number(int n) {
    int digits = 0;
    int d = 1;
    while (n / d > 0) {
        d *= 10;
        digits++;
    }

    auto cstr = new char[digits + 1];
    sprintf(cstr, "%d", n);

    if (digits < 3) {
        delete[] cstr;
        return false;
    }

    for (int i = 0; i <= digits - 3; i++) {
        if (cstr[i] == '6' && cstr[i + 1] == '6' && cstr[i + 2] == '6') {
            delete[] cstr;
            return true;
        }
    }

    delete[] cstr;
    return false;
}

int main() {
    int n;
    cin >> n;

    int i = 0;
    int k = 0;
    while (i < n) {
        k++;
        if (is_end_number(k)) i++;
    }
    cout << k;
}