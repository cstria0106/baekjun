/*
 * 미해결
 */

#include <iostream>

using namespace std;

unsigned long long counts[101] = {0};

unsigned long long get_stair_number_count(int n) {
    if (n == 1) return 9;
    if (counts[n] != 0) return counts[n];
    return counts[n];
}

int main() {
    int n;
    cin >> n;

    cout << get_stair_number_count(n) % 1000000000 << endl;
}