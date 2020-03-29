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

    void print() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                printf("%c", canvas[y][x]);
            }
            printf("\n");
        }
    }
};

class Snail {
private:
    int x, y;
    int size;
    int width, height;

public:
    void draw(Canvas &canvas) {
        for (int dy = 0; dy < height; dy++) {
            int ry = y + dy;
            int dl = 0;
            int dr = width - 1;
            int rl = x + dl;
            int rr = x + dr;


            if (dy == 0 || dy == height - 1) {
                for (int rx = rl; rx <= rr; rx++) {
                    canvas.draw(rx, ry, '*');
                }
            } else {
                canvas.draw(rl, ry, '*');
                canvas.draw(rr, ry, '*');
            }
        }

        if (size != 1) {
            Snail(x + 2, y + 2, size - 1).draw(canvas);
        }
    }

    explicit Snail(int x, int y, int size) : x(x), y(y), size(size) {
        width = 1 + (size - 1) * 4;
        height = width;
    }
};

int main() {
    int n;
    scanf("%d", &n);

    int width = 1 + (n - 1) * 4;
    int height = width;

    Canvas canvas = Canvas(width, height);

    Snail(0, 0, n).draw(canvas);

    canvas.print();
}