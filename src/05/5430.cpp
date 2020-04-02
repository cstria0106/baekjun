#include "../main.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

int main_() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string p, x;
        int n;
        cin >> p >> n >> x;

        deque<int> array;

        string::iterator iter = x.begin() + 1;
        for (int j = 0; j < n; j++) {
            auto start = iter;
            while (*(iter + 1) <= '9' && *(iter + 1) >= '0') {
                iter++;
            }
            string digit = x.substr(start - x.begin(), iter - start + 1);
            array.push_back(strtol(digit.c_str(), nullptr, 10));
            iter += 2;
        }

        bool error = false;
        bool reverse = false;

        for (char c: p) {
            if (c == 'R') {
                reverse = !reverse;
            } else if (c == 'D') {
                if (array.empty()) {
                    error = true;
                    break;
                }
                if (reverse) {
                    array.pop_back();
                } else {
                    array.pop_front();
                }

            }
        }

        if (!error) {
            cout << "[";
            while (!array.empty()) {
                if (reverse) {
                    cout << array.back();
                    array.pop_back();
                } else {
                    cout << array.front();
                    array.pop_front();
                }
                if (!array.empty()) cout << ",";
            }
            cout << "]" << endl;
        } else {
            cout << "error" << endl;
        }
    }

    return 0;
}