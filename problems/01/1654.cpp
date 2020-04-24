
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n;

    cin >> k >> n;

    vector<unsigned int> lengths(k);
    unsigned int max_length = 0;

    for (auto &length: lengths) {
        cin >> length;
        if (max_length < length) max_length = length;
    }

    unsigned int right = max_length;
    unsigned int left = 1;
    unsigned int middle;

    while (true) {
        middle = (right + left) / 2;
        unsigned int count_a = 0;
        unsigned int count_b = 0;

        for (auto &length: lengths) {
            count_a += length / middle;
            count_b += length / (middle + 1);
        }

        if (count_b >= n) {
            left = middle + 1;
        } else if (count_a < n) {
            right = middle - 1;
        } else {
            break;
        }
    }

    cout << middle << endl;

    return 0;
}