#include "../main.h"
#include <iostream>
#include <string>

using namespace std;

int main_() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        int sum = s[0] + s[2] - '0' * 2;
        cout << sum << endl;
    }


    return 0;
}