#include <iostream>

using namespace std;

int get_distance(char a, char b) {
    if (b >= a) return b - a;
    else return (b + 26) - a;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1;
        string s2;
        s1.reserve(21);
        s2.reserve(21);
        cin >> s1 >> s2;

        cout << "Distances: ";
        for (size_t j = 0; j < s1.length(); j++) {
            cout << get_distance(s1[j], s2[j]) << " ";
        }
        cout << endl;
    }
}