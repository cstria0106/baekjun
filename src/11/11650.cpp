/**
 * 미해결
 */

#include<cstdio>
#include<algorithm>

using namespace std;

typedef struct point {
    int x, y;

    point() {
        x = 0;
        y = 0;
    }
} Point;

int main() {
    int n;
    scanf("%d", &n);

    auto *points = new Point[n];

    for (int i = 0; i < n; i++) {
        Point point;
        scanf("%d %d", &point.x, &point.y);
        points[i] = point;
    }

    sort(points, points + n, [](const Point &a, const Point &b) -> bool {
        if (a.x < b.x) return true;
        return a.y < b.y;
    });

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    delete[] points;
}