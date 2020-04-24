#include <iostream>

using namespace std;

struct Pair {
    int zero;
    int one;
};

Pair *pairs;
bool *has_pair;

Pair fibonacci(int n) {
    if (n == 0) return {1, 0};
    if (n == 1) return {0, 1};
    if (has_pair[n]) return pairs[n];
    Pair pair_before = fibonacci(n - 1);
    pairs[n] = {pair_before.one, pair_before.one + pair_before.zero};
    has_pair[n] = true;
    return pairs[n];
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        pairs = new Pair[n + 1];
        has_pair = new bool[n + 1];
        for (int j = 0; j < n + 1; j++) has_pair[j] = false;

        Pair pair = fibonacci(n);
        cout << pair.zero << " " << pair.one << endl;

        delete[] pairs;
        delete[] has_pair;
    }


    return 0;
}