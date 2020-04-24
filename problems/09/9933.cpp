#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> array;
    vector<string> reversed_array;
    array.reserve(n);
    reversed_array.reserve(n);

    for (int i = 0; i < n; i++) {
        string s;
        s.reserve(14);
        cin >> s;
        array.push_back(s);

        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        reversed_array.push_back(reversed);

        for (const string &r: reversed_array) {
            if (r == s) {
                cout << s.length() << " " << s[s.length() / 2] << endl;
                return 0;
            }
        }
    }
}