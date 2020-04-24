/**
 * 미해결
 */

#include <iostream>
#include <cmath>

using namespace std;

class Circle {
public:
    double x, y;
    double radius;

    Circle(double x, double y, double radius) : x(x), y(y), radius(radius) {}

    Circle() : Circle(0, 0, 0) {}

    double distance_of_center(const Circle &other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    int get_tangent_point_count(const Circle &other) {
        double distance = distance_of_center(other);

        if (distance == 0) {
            if (radius == other.radius) return -1;
            return 0;
        }
        if (distance < radius) {
            if (distance + other.radius < radius) return 0;
            if (distance + other.radius > radius) return 2;
            return 1;
        }
        if (distance > radius) {
            if (distance - other.radius < radius) return 2;
            if (distance - other.radius > radius) return 0;
            return 1;
        }
        return 2;
    }
};

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Circle a, b;
        cin >> a.x >> a.y >> a.radius;
        cin >> b.x >> b.y >> b.radius;

        cout << a.get_tangent_point_count(b) << endl;
    }

    return 0;
}