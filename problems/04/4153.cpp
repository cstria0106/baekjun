#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int sides[3];

    while (true) {
        cin >> sides[0] >> sides[1] >> sides[2];
        sort(sides, sides + 3);

        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0) break;
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
}