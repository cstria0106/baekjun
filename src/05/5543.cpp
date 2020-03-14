#include <iostream>

using namespace std;

int main() {
    int prices[5];
    for (int &price : prices) {
        cin >> price;
    }

    int set_prices[6];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            set_prices[i * 2 + j] = prices[i] + prices[3 + j] - 50;
        }
    }

    int min = set_prices[0];
    for (int i = 1; i < 6; i++) {
        if (min > set_prices[i]) min = set_prices[i];
    }

    cout << min;
}