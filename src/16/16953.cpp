/**
 * 미해결
 */

#include <iostream>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    int step = 1;

    while (b != a && b != 0) {
        if (b % 2 == 0) b /= 2;
        else {
            b /= 10;
        }
        step++;
    }

    if (b == a) cout << step << endl;
    else cout << "-1" << endl;
}