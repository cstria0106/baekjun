/**
 * 미해결
 */
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto array = new unsigned long long[n + 2];

    array[1] = 1;
    array[2] = 2;

    for (int i = 3; i <= n; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }

    cout << array[n] % 15746 << endl;
}