#include "../main.h"
#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

void print_sum(string &a, string &b) {
    vector<unsigned char> a_digits(10001, 0);
    vector<unsigned char> b_digits(10001, 0);

    for (size_t i = 0; i < a.size(); i++) a_digits[a_digits.size() - 1 - i] = a[a.size() - 1 - i] - '0';
    for (size_t i = 0; i < b.size(); i++) b_digits[b_digits.size() - 1 - i] = b[b.size() - 1 - i] - '0';

    vector<unsigned char> c_digits(10001, 0);
    for (size_t i = 10000; i > 0; i--) {
        c_digits[i] += a_digits[i] + b_digits[i];
        if (c_digits[i] >= 10) {
            c_digits[i] -= 10;
            c_digits[i - 1]++;
        }
    }

    int i = 0;
    while (c_digits[i] == 0) i++;

    while (i < 10001) {
        cout << (int) c_digits[i];
        i++;
    }
    cout << endl;
}

int main_() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        print_sum(a, b);
    }

    return 0;
}