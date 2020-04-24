#include <iostream>

using namespace std;

int main() {
    unsigned long long int min, max;
    cin >> min >> max;

    bool *is_sqr_n = new bool[max - min + 1]{false};

    unsigned long long int n = 1;

    do {
        n++;
        if (n * n > max) break;

        unsigned long long int i = min / (n * n) - 1;
        do {
            i++;
            if (n * n * i > max) break;

            if (n * n * i >= min) is_sqr_n[n * n * i - min] = true;
        } while (true);
    } while (true);

    int count = 0;
    for (unsigned long long int i = 0; i < max - min + 1; i++) {
        if (!is_sqr_n[i]) {
            count++;
        }
    }

    cout << count << endl;

}