#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    s.reserve(1001);
    cin >> s;

    vector<string> suffixes;
    suffixes.reserve(1001);
    for (unsigned long long i = 0; i < s.size(); i++) {
        suffixes.push_back(s.substr(i));
    }

    sort(suffixes.begin(), suffixes.end());

    for (string &suffix: suffixes) {
        cout << suffix << endl;
    }
}