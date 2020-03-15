/**
 * ¹ÌÇØ°á
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        if (distance == 0) {
            if (r1 == r2) {
                cout << "-1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (distance > r1 + r2) {
            cout << "0" << endl;
        } else if (distance == r1 + r2) {
            cout << "1" << endl;
        } else {
            cout << "2" << endl;
        }
    }
}