/**
 * 미해결
 */
#include <iostream>

using namespace std;

class Consult {
public:
    int duration;
    int profit;

    Consult() {
        this->duration = 0;
        this->profit = 0;
    }

    Consult(int duration, int profit) {
        this->duration = duration;
        this->profit = profit;
    }
};

int main() {
    int n;
    cin >> n;

    auto *consults = new Consult[n];

    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;

    }

    delete[] consults;
}