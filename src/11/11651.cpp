#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct Point {
    int x, y;
};

int main_() {
    int n;
    scanf("%d", &n);

    vector<Point> points(n);

    for (Point &point: points) {
        scanf("%d %d", &point.x, &point.y);
    }

    sort(points.begin(), points.end(), [](const Point &a, const Point &b) -> bool {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    return 0;
}