#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool is_group_word(const string &s) {
    set<char> group_element;
    char last_char = '\0';
    for (char c: s) {
        if (last_char == c) continue;
        if (binary_search(group_element.begin(), group_element.end(), c)) return false;

        last_char = c;
        group_element.insert(c);
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (is_group_word(s)) {
            count++;
        }
    }

    cout << count << endl;

}