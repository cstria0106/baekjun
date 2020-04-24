#include <vector>
#include <iostream>

long long sum(std::vector<int> &a) {
    int n = 0;
    for (int i: a) {
        n += i;
    }
    return n;
}

int main() {
    std::vector<int> v = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sum(v);
}