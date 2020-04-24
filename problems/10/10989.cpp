#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int numbers[10001] = {0};
    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);

        numbers[number]++;
    }

    for (int i = 0; i < 10001; i++) {
        for (int j = 0; j < numbers[i]; j++) {
            printf("%d\n", i);
        }
    }
}