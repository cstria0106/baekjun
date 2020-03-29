#include <iostream>

using namespace std;

unsigned long long methods[1001] = {0};

unsigned long long get_methods(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (methods[n] != 0) return methods[n];

    methods[n] = get_methods(n - 1) + get_methods(n - 2);
    return methods[n];
}

int main() {
    int n;
    cin >> n;
    cout << get_methods(n) % 10007 << endl;
}