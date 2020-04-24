#include <cstdio>

#define MAX 10000

int construct(int n) {
    int m = n;
    int constructed = n;
    while (m >= 1) {
        constructed += m % 10;
        m /= 10;
    }

    return constructed;
}

int main() {
    bool not_self_number[MAX + 1] = {false};
    for (int i = 1; i <= MAX; i++) {
        int constructed = construct(i);
        if (constructed <= MAX) not_self_number[constructed] = true;
    }

    for (int i = 1; i <= MAX; i++) {
        if (!not_self_number[i]) {
            printf("%d\n", i);
        }
    }
}