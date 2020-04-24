/**
 * 미해겷
 */

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int array[50];
    int sorted[50];
    int indexes[1001];
    int count[1001] = {0};

    for (int i = 0; i < n; i++) {
        cin >> array[i];
        sorted[i] = array[i];
        count[array[i]]++;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sorted[i] > sorted[j]) {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
            indexes[sorted[i]] = i;
            indexes[sorted[j]] = j;
        }
    }

    int i = 0;
    while (i < n) {
        for (int j = count[array[i]] - 1; j >= 0; j--) {
            cout << indexes[array[i]] - j << " ";
        }
        i += count[array[i]];
    }
}