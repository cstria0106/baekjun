#include <iostream>

using namespace std;

int make_positive(int n) {
    return n > 0 ? n : -n;
}

int main() {
    int c1['z' - 'a' + 1] = {0}, c2['z' - 'a' + 1] = {0};
    string s1, s2;
    s1.reserve(1001);
    s2.reserve(1001);
    cin >> s1 >> s2;

    for (char c: s1) c1[c - 'a']++;
    for (char c: s2) c2[c - 'a']++;

    int count = 0;
    for (int i = 0; i < 'z' - 'a'; i++) {
        count += make_positive(c1[i] - c2[i]);
    }
    cout << count << endl;
}