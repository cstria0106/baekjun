#include <iostream>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    int *values = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int coin_count = 0;
    int sum = 0;
    int value_cursor = n - 1;

    while (value_cursor >= 0 && sum != k) {
        int value = values[value_cursor--];

        if (value > k) continue;

        coin_count += (k - sum) / value;
        sum += (k - sum) / value * value;
    }

    cout << coin_count;
}
