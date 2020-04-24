#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool is_palindrome(string s) {
    for (size_t i = 0; i < (s.size() + 1) / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }

    return true;
}

bool is_palindrome(int n) {
    char digits[6];
    sprintf(digits, "%d", n);

    return is_palindrome(string(digits));
}

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        if (is_palindrome(n)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}