#include <iostream>
#include <functional>

using namespace std;

typedef struct point {
    int x, y;

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
} Point;

function<void(int x, int y, int nth)> on_visit;

static int footprint = 0;

void visit(Point left_top, int size, Point target_point) {
    if (size == 1) {
        on_visit(left_top.x, left_top.y, footprint++);
    } else {
        int center_x = left_top.x + size / 2;
        int center_y = left_top.y + size / 2;

        if (target_point.x < center_x && target_point.y < center_y) {
            visit(left_top, size / 2, target_point);
        } else {
            footprint += size * size / 4;
        }
        if (target_point.x >= center_x && target_point.y < center_y) {
            visit(Point(left_top.x + size / 2, left_top.y), size / 2, target_point);
        } else {
            footprint += size * size / 4;
        }
        if (target_point.x < center_x && target_point.y >= center_y) {
            visit(Point(left_top.x, left_top.y + size / 2), size / 2, target_point);
        } else {
            footprint += size * size / 4;
        }
        if (target_point.x >= center_x && target_point.y >= center_y) {
            visit(Point(left_top.x + size / 2, left_top.y + size / 2), size / 2, target_point);
        } else {
            footprint += size * size / 4 * 3;
        }
    }
}

int main() {
    int sqrt;
    cin >> sqrt;
    int size = 1;
    for (int i = 0; i < sqrt; i++) {
        size *= 2;
    }

    int x, y;
    cin >> y >> x;

    Point target_point(x, y);

    on_visit = [x, y](int visited_x, int visited_y, int nth) -> void {
        if (visited_x == x && visited_y == y) {
            cout << nth << endl;
        }
    };

    visit(Point(0, 0), size, target_point);
}