#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_good_word(const string &word) {
    stack<char> stack;
    bool flags['B' - 'A' + 1] = {false};

    for (char c: word) {
        if (!flags[c - 'A']) {
            stack.push(c);
            flags[c - 'A'] = true;
        } else {
            if (stack.top() == c) stack.pop();
            else return false;
            flags[c - 'A'] = false;
        }
    }

    return stack.empty();
}

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        s.reserve(100000);
        cin >> s;
        if (is_good_word(s)) count++;
    }

    cout << count << endl;
}