#include <iostream>
#include <string>

using namespace std;

int get_required_set(const string &s) {
    int digits[10] = {0};
    for (char c : s) {
        digits[c - '0']++;
    }
    int six_nine_average = (1 + digits[6] + digits[9]) / 2;
    digits[6] = six_nine_average;
    digits[9] = six_nine_average;

    int max = digits[0];
    for (int i = 1; i < 10; i++) {
        if (max < digits[i]) max = digits[i];
    }

    return max;
}

int main() {
    string s;
    cin >> s;
    cout << get_required_set(s) << endl;
}