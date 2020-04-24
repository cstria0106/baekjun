#include <iostream>

using namespace std;

unsigned long long get_cut_tree(const unsigned long long trees[1000000], int len, int n) {
    unsigned long long sum = 0;
    for (int i = 0; i < len; i++) {
        sum += (trees[i] > n ? (trees[i] - n) : 0);
    }

    return sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    unsigned long long trees[100000];
    unsigned long long min = 1000000000;
    unsigned long long max = 0;
    for (int i = 0; i < n; i++) {
        cin >> trees[i];
        if (min > trees[i]) min = trees[i];
        if (max < trees[i]) max = trees[i];
    }

    unsigned long long l = 0;
    unsigned long long r = max;
    unsigned long long c = (l + r) / 2;
    while (l <= r) {
        c = (l + r) / 2;
        unsigned long long tree_h = get_cut_tree(trees, n, c);
        unsigned long long tree_h_plus = get_cut_tree(trees, n, c + 1);
        if (tree_h < m) {
            r = c - 1;
        } else if (tree_h_plus >= m) {
            l = c + 1;
        } else {
            break;
        }
    }

    cout << c << endl;

    return 0;
}