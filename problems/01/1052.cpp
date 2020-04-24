/*
 * 미해결
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void drive(vector<int>::iterator from, vector<int>::iterator to, int &filled) {
    int i = 0;
    for (i = 0; i < (to - from) / 2; i += 1) {
        from[i] *= 2;
    }
    for (; i < to - from; i += 1) {
        from[i] = 0;
    }
    filled -= (to - from) / 2;
}

void distribute(vector<int> bottles, int &filled, int &bought) {
}

void buy(vector<int> bottles, int &filled, int &bought) {
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> bottles;
    bottles.resize(n);
    fill(bottles.begin(), bottles.end(), 1);

    int filled = n;
    int bought = 0;

    while (filled > k) {
        int square = 1;
        while (filled / square > k) square *= 2;

        while (square > 1) {
            drive(bottles.begin(), bottles.begin() + square, filled);
            square /= 2;
        }

        for (int i: bottles) {
            cout << i << " ";
        }
        cout << endl;
    }
}