#include <cstdio>
#include <cstring>

using namespace std;

class Point {
public:
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Triangle {
public:
    Point position;
    int size;

    Triangle(const Point position, const int size) : position(position), size(size) {}

    void apply(bool *array, int width) {
        if (size == 3) {
            for (int y = position.y; y < position.y + size; y++) {
                auto line = array + width * y;
                if (y == position.y + size - 1) {
                    for (int x = position.x; x < position.x + size * 2 - 1; x++) {
                        line[x] = true;
                    }
                } else {
                    int left = position.x + size - (y - position.y) - 1;
                    int right = position.x + size + (y - position.y) - 1;
                    line[left] = true;
                    line[right] = true;
                }
            }
        } else {
            Triangle up(Point(position.x + size / 2, position.y), size / 2);
            Triangle left(Point(position.x, position.y + size / 2), size / 2);
            Triangle right(Point(position.x + size, position.y + size / 2), size / 2);
            up.apply(array, width);
            left.apply(array, width);
            right.apply(array, width);
        }
    }
};

int main() {
    int size;
    scanf("%d", &size);

    int width = size * 2 - 1;
    int height = size;
    auto array = new bool[width * height];

    memset(array, false, width * height);

    Triangle(Point(0, 0), size).apply(array, width);

    for (int y = 0; y < height; y++) {
        bool *line = array + width * y;
        for (int x = 0; x < width; x++) {
            printf((line[x] ? "*" : " "));
        }
        printf("\n");
    }
}