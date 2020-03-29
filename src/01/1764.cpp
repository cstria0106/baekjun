#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> no_hear;
    vector<string> no_hear_listen;
    no_hear.reserve(n);
    no_hear_listen.reserve(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        no_hear.push_back(s);
    }

    sort(no_hear.begin(), no_hear.end());

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (binary_search(no_hear.begin(), no_hear.end(), s)) {
            no_hear_listen.push_back(s);
        }
    }

    sort(no_hear_listen.begin(), no_hear_listen.end());
    printf("%d\n", no_hear_listen.size());
    for (string s: no_hear_listen) {
        printf("%s\n", s.c_str());
    }
}