#include <iostream>

using namespace std;

int costs[1000001] = {0};

int get_cost(int x) {
    if (x == 1) return 0;
    if (x == 2) return 1;
    if (x == 3) return 1;
    if (costs[x] != 0) return costs[x];

    int min = get_cost(x - 1);
    if (x % 3 == 0 && min > get_cost(x / 3)) min = get_cost(x / 3);
    if (x % 2 == 0 && min > get_cost(x / 2)) min = get_cost(x / 2);

    costs[x] = 1 + min;
    return costs[x];
}

int main() {
    int x;
    cin >> x;

    cout << get_cost(x) << endl;
}