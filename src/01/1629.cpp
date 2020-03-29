/*
 * 미해결
 */
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int delta = a - c;
    if (delta == 0) {
        cout << "0" << endl;
        return 0;
    }
    int loop = (a / delta) * (a / delta > 0 ? 1 : -1) + 1;
    int result = a + (delta * ((b - 1) % loop));

    cout << "delta: " << delta << endl;
    cout << "loop: " << loop << endl;
    cout << "result: " << result << endl;

}