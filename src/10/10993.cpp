#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Canvas {
private:
    int width, height;
    vector<vector<char>> canvas;
public:
    Canvas(int width, int height) : width(width), height(height) {
        canvas.resize(height);
        for (vector<char> &line: canvas) {
            line.resize(width);
            fill(line.begin(), line.end(), ' ');
        }
    }

    void draw(int x, int y, char c) {
        canvas[y][x] = c;
    }

    void print(bool reversed) {
        for (int y = 0; y < height; y++) {
            int w;
            if (reversed) w = width - y;
            else w = width / 2 + y + 1;
            for (int x = 0; x < w; x++) {
                printf("%c", canvas[y][x]);
            }
            printf("\n");
        }
    }
};

class Triangle {
private:
    int x, y;
    int width, height;
    int size;
    bool reversed;
public:
    void draw(Canvas &canvas) {
        for (int dy = 0; dy < height; dy++) {
            int ry = y + dy;
            if (reversed) ry = y + height - dy - 1;

            if (dy == height - 1) {
                for (int dx = 0; dx < width; dx++) {
                    int rx = x + dx;
                    canvas.draw(rx, ry, '*');
                }
            }

            int left = width / 2 - dy;
            int right = width / 2 + dy;
            canvas.draw(x + left, ry, '*');
            canvas.draw(x + right, ry, '*');
        }

        if (size != 1) {
            if (reversed) {
                Triangle(x + width / 4 + 1, y + 1, size - 1, !reversed).draw(canvas);
            } else {
                Triangle(x + width / 4 + 1, y + height / 2, size - 1, !reversed).draw(canvas);
            }
        }
    }

    explicit Triangle(int x, int y, int size, bool reversed) : x(x), y(y), size(size), reversed(reversed) {
        height = 0;
        for (int i = 0; i < size; i++) {
            height += pow(2, i);
        }
        width = height * 2 - 1;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    int height = 0;
    for (int i = 0; i < n; i++) {
        height += pow(2, i);
    }
    int width = height * 2 - 1;

    Canvas canvas = Canvas(width, height);

    bool reversed = n % 2 == 0;
    Triangle(0, 0, n, reversed).draw(canvas);

    canvas.print(reversed);
}