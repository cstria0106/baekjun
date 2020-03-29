#include <iostream>
#include <cstdlib>

using namespace std;

long min(int n) {
    char s[8];
    sprintf(s, "%d", n);

    for (char &c:s) if (c == '6') c = '5';

    return strtol(s, nullptr, 10);
}

long max(int n) {
    char s[8];
    sprintf(s, "%d", n);

    for (char &c:s) if (c == '5') c = '6';

    return strtol(s, nullptr, 10);
}

int main() {
    int a, b;
    cin >> a >> b;

    int result_min = min(a) + min(b);
    int result_max = max(a) + max(b);

    cout << result_min << " " << result_max << endl;
}