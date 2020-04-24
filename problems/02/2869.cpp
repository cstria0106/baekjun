
#include <iostream>

using namespace std;

int main() {
    int a, b, v;
    cin >> a >> b >> v;

    cout << ((a == v) ? 1 : (v - a - 1) / (a - b) + 2) << endl;

    return 0;
}