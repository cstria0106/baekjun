#include <iostream>
#include <string>
#include <cmath>

unsigned long long add_mod(unsigned long long a, unsigned long long b, unsigned long long n) {
    a %= n;
    b %= n;
    if (a == 0) return b;
    if (b == 0) return a;
    if (a + b < a) {
        return (a + b - n) % n;
    }
    return (a + b) % n;
}

unsigned long long mul_mod(unsigned long long a, unsigned long long b, unsigned long long n) {
    a %= n;
    b %= n;
    if (a == 0 || b == 0) return 0;
    if (a == 1) return b;
    if (b == 1) return a;

    unsigned long long a_squared = mul_mod(a, b / 2, n);
    if ((b & 1) == 0) {
        return add_mod(a_squared, a_squared, n);
    }
    return add_mod(a, add_mod(a_squared, a_squared, n), n);
}

unsigned long long pow_mod(unsigned long long a, unsigned long long d, unsigned long long n) {
    unsigned long long ret = 1;

    if (d == 0) return 1;
    for (unsigned long long i = 0; i < d; i++) {
        ret = mul_mod(ret, a, n);
    }

    return ret;
}

unsigned long long hash(const std::string &s) {
    unsigned long long sum = 0;

    int i = 0;
    for (char c: s) {
        int n = 1234567891;
        sum = add_mod(sum, mul_mod(c - 'a' + 1, pow_mod(31, i++, n), n), n);
    }

    return sum;
}

int main_() {
    int l;
    std::cin >> l;

    std::string s;
    s.reserve(l);
    std::cin >> s;

    std::cout << hash(s) << std::endl;

    return 0;
}