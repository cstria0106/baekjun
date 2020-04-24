/**
 * 미해결
 */

#include <iostream>
#include <vector>

class Point {
public:
    int x, y;

    int distance_to(Point other) {
        int dx = this->x - other.x;
        int dy = this->y - other.y;
        return dx * dx + dy * dy;
    }

    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

using namespace std;

int main() {
    int n;
    cin >> n;

    auto *points = new Point[n];

    int min = Point(-10000, -10000).distance_to(Point(10000, 10000));
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;

        for (int j = 0; j < i; j++) {
            int distance = points[i].distance_to(points[j]);
            if (min > distance) {
                min = distance;
            }
        }
    }

    cout << min;
}