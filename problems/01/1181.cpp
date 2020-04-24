#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto compare = [](const string &a, const string &b) -> bool {
        if (a.length() < b.length()) return true;
        if (a.length() > b.length()) return false;
        return a.compare(b) < 0;
    };
    set<string, decltype(compare)> set(compare);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set.insert(s);
    }

    for_each(set.begin(), set.end(), [](const string &s) {
        printf("%s\n", s.c_str());
    });
}

