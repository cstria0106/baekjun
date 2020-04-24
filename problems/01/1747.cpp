#include <iostream>
#include <cstdio>

using namespace std;

bool is_prime_number(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

bool is_palindrome(int n) {
    int digit_count = 0;
    for (int d = 1; n / d >= 1; d *= 10) digit_count++;
    char *digit_string = new char[digit_count + 1];
    sprintf(digit_string, "%d", n);

    for (int i = 0; i < digit_count / 2; i++) if (digit_string[i] != digit_string[digit_count - 1 - i]) return false;

    return true;
}

int main() {
    int n;
    cin >> n;

    while (!is_prime_number(n) || !is_palindrome(n)) n++;

    cout << n << endl;
}
