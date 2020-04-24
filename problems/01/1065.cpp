#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_hansu(int n) {
    vector<int> digits;

    int m = n;

    while (m >= 1) {
        digits.push_back(m % 10);
        m /= 10;
    }

    if (digits.size() > 2) {
        reverse(digits.begin(), digits.end());
        int d = digits[1] - digits[0];

        for (auto i = 1ull; i < digits.size() - 1; i++) {
            if (digits[i + 1] - digits[i] != d) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (is_hansu(i)) count++;
    }

    cout << count;
}