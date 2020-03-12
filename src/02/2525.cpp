#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    int timer;
    cin >> timer;

    m += timer;
    h += m / 60;
    m %= 60;
    h %= 24;

    cout << h << " " << m << endl;
}
