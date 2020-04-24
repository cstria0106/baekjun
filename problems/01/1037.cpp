#include <cstring>
#include <cstdio>

int main() {
    char str[10001];
    scanf("%s", str);

    int len = strlen(str);

    int joies = 0;
    int ioies = 0;

    char *cursor = str;
    while (cursor - str + 3 <= len) {
        if (cursor[0] == 'J' && cursor[1] == 'O' && cursor[2] == 'I') {
            joies++;
            cursor += 2;
        } else if (cursor[0] == 'I' && cursor[1] == 'O' && cursor[2] == 'I') {
            ioies++;
            cursor += 2;
        } else {
            cursor++;
        }
    }

    printf("%d\n%d", joies, ioies);
}