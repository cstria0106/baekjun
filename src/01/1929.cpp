#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int m, n;

    cin >> m >> n;

    bool is_not_prime[1000001] = {false};
    is_not_prime[1] = true;

    for (int i = 2; i * i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            is_not_prime[j] = true;
        }
    }

    for (int i = m; i <= n; i++) {
        if (!is_not_prime[i]) {
            printf("%d\n", i);
        }
    }
}