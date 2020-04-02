#include "../main.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> max_array;

int get_max(int x, int y) {
    if (y == 0) return v[0][0];
    if (max_array[y][x] != 0) return max_array[y][x];
    if (x == 0) return v[y][x] + get_max(0, y - 1);
    if (x == y) return v[y][x] + get_max(x - 1, y - 1);

    int a = get_max(x - 1, y - 1);
    int b = get_max(x, y - 1);
    max_array[y][x] = v[y][x] + (a > b ? a : b);
    return max_array[y][x];
}

int main_() {
    int n;
    cin >> n;

    v.resize(n);
    max_array.resize(n);

    for (int i = 0; i < n; i++) {
        v[i].resize(i + 1);
        max_array[i].resize(i + 1);

        for (int &j: max_array[i]) j = 0;
        for (int j = 0; j < i + 1; j++) {
            cin >> v[i][j];
        }
    }

    int max = get_max(0, n - 1);
    for (int i = 1; i < n; i++) {
        int n_max = get_max(i, n - 1);
        if (max < n_max) max = n_max;
    }

    cout << max << endl;


    return 0;
}