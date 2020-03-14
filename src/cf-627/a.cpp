#include<iostream>

using namespace std;

bool is_cleared(int *lines, int width) {
    bool flag = true;

    for (int i = 0; i < width - 1; i++) {
        if (lines[i] != lines[i + 1]) flag = false;
    }

    return flag;
}

bool can_clear(int *lines, int width) {
    int step = 0;

    int max = 0;
    for (int i = 0; i < width; i++) {
        if (lines[i] > max) {
            max = lines[i];
        }
    }

    while (step++ < (max / 2 + 1) * width && !is_cleared(lines, width)) {
        int min_line_index = 0;
        for (int i = 1; i < width; i++) {
            if (lines[i] < lines[min_line_index]) {
                min_line_index = i;
            }
        }

        lines[min_line_index] += 2;
    }

    return is_cleared(lines, width);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int width;
        cin >> width;

        int *lines = new int[width];

        for (int x = 0; x < width; x++) {
            cin >> lines[x];
        }

        cout << (can_clear(lines, width) ? "YES" : "NO") << endl;


        delete[] lines;
    }
}