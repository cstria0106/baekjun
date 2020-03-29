#include <cstdio>

using namespace std;

void hanoi(int from, int to, int height) {
    if (height == 1) {
        printf("1 3\n");
        return;
    }
    hanoi(1, 2, height - 1);
    printf("%d %d\n", from, to);
    hanoi(2, 1, height - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    hanoi(1, 3, n);
}