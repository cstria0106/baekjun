#include "../main.h"
#include <iostream>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int n;
vector<int> arr;
vector<bool> max_array_calculated;
vector<int> max_array;

int get_max(int from) {
    if (from == n - 1) return arr[from];
    if (max_array_calculated[from]) return max_array[from];
    auto a = arr[from] + get_max(from + 1);
    auto b = arr[from];
    max_array[from] = MAX(a, b);
    max_array_calculated[from] = true;
    return max_array[from];

}

int main_() {
    cin >> n;
    arr.resize(n);
    for (auto &i: arr) cin >> i;

    max_array = vector<int>(n);
    max_array_calculated = vector<bool>(n, false);

    int max = get_max(0);
    for (int i = 1; i < n; i++) {
        if (max < get_max(i)) max = get_max(i);
    }

    cout << max << endl;

    return 0;
}