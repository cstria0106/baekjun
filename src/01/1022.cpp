#include "../main.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}
};

int get_range_top(int depth) {
    if (depth == 1) return 1;

    int sum = 1;
    for (int i = 2; i <= depth; i++) {
        sum += (i * 2 - 1) * 4 - 4;

    }

    return sum;
}

int get_number(Point p) {
    int depth = abs(p.x) > abs(p.y) ? abs(p.x) : abs(p.y);
    int from = get_range_top(depth) + 1;
    int n = from;
    if (p.x == depth && p.y != depth) {
        n += depth - 1 - p.y;
    } else if (p.y == -depth) {
        n += (depth) * 2 - 1;
        n += depth - p.x;
    } else if (p.x == -depth) {
        n += (depth) * 2 - 1;
        n += (depth) * 2;
        n += depth + p.y;
    } else {
        n += (depth) * 2 - 1;
        n += (depth) * 4;
        n += depth + p.x;
    }

    return n;
}

int main_() {
    int r1, c1, r2, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int max_len = 0;
    for (int y = r1; y <= r2; y++) {
        for (int x = c1; x <= c2; x++) {
            int len = (int) log10(get_number({x, y})) + 1;
            if (len > max_len) max_len = len;
        }
    }

    printf("%d\n", max_len);

    char f_str[100];

    for (int y = r1; y <= r2; y++) {
        for (int x = c1; x <= c2; x++) {
            if (x == c1) {
                sprintf(f_str, "%%%dd", max_len);
                printf(f_str, get_number({x, y}));
            } else {
                sprintf(f_str, "%%%dd", max_len + 1);
                printf(f_str, get_number({x, y}));
            }
        }
        printf("\n");
    }

    return 0;
}