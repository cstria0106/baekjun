
#include <iostream>
#include <cmath>

using namespace std;

int term_count[100001] = {0};

int get_term_count(int n) {
    if (n == 1) return 1;
    if (term_count[n] != 0) return term_count[n];

    int min_count = n;
    for (int i = 1; i <= (int) sqrt(n); i++) {
        int count = 1 + get_term_count((n - i * i));
        if (count < min_count) min_count = count;
    }
    term_count[n] = min_count;
    return min_count;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) get_term_count(i);
    cout << get_term_count(n) << endl;

    return 0;
}