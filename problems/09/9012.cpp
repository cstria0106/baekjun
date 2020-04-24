#include <iostream>
#include <string>

using namespace std;

bool is_vps(string str) {
    int n = 0;
    for (char i : str) {
        if (i == '(') n++;
        if (i == ')') n--;
        if (n < 0) return false;
    }

    return n == 0;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        if (is_vps(input)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}