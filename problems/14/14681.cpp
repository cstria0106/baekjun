#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int quadrant = 0;
    if (y > 0) {
        if (x > 0) {
            quadrant = 1;
        }
        if (x < 0) {
            quadrant = 2;
        }
    }
    if (y < 0) {
        if (x < 0) {
            quadrant = 3;
        }
        if (x > 0) {
            quadrant = 4;
        }
    }

    cout << quadrant << endl;
}