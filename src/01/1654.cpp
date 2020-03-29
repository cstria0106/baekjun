#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k, n;

    cin >> k >> n;

    int *lengths = new int[k];
    int sum = 0;

    for (int i = 0; i < k; i++) {
        cin >> lengths[i];
        sum += lengths[i];
    }

    int average = (sum + 1) / n;

    int count;
    int length = average + 1;

    do {
        length--;
        count = 0;
        for (int i = 0; i < k; i++) {
            count += lengths[i] / length;
        }
    } while (count < n);

    cout << length << endl;

    delete[] lengths;
}