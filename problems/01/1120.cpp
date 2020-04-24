#include <iostream>

using namespace std;

int get_difference(const string &a, const string &b) {
    int count = 0;
    for (unsigned long long i = 0; i < a.size(); i++) if (a[i] != b[i]) count++;
    return count;
}

int main() {
    string a, b;
    a.reserve(51);
    b.reserve(51);
    cin >> a >> b;

    int min = 50;
    for (int left = 0; left + a.size() <= b.size(); left++) {
        int difference = get_difference(a, b.substr(left));
        if (difference < min) {
            min = difference;
        }
    }
    cout << min << endl;
}