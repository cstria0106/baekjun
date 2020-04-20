#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

template<typename T, typename C>
void stalin_sort(vector<T> &v, C compare) {
    if (v.empty()) return;
    for (auto iter = v.begin(); iter < v.end() - 1; iter++) {
        if (!compare(*iter, *(iter + 1))) {
            v.erase(iter + 1);
            iter--;
        }
    }
}

int main() {
    vector<int> v;

    v.push_back(4);
    v.push_back(6);
    v.push_back(10);
    v.push_back(1);
    v.push_back(0);
    v.push_back(30);

    stalin_sort(v, [](const int &a, const int &b) -> bool {
        return a < b;
    });

    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}

