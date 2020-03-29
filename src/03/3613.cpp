#include <iostream>
#include <string>

using namespace std;

bool is_java_style(const string &s) {
    if (s[0] >= 'A' && s[0] <= 'Z') return false;
    for (char c: s) {
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')) return false;
    }
    return true;
}

bool is_c_style(const string &s) {
    if (s[0] == '_' || s[s.length() - 1] == '_') return false;
    for (char c: s) {
        if ((c < 'a' || c > 'z') && c != '_') return false;
    }
    for (size_t i = 0; i < s.length() - 1; i++) {
        if (s[i] == '_' && s[i + 1] == '_') return false;
    }
    return true;
}

string to_java_style(const string &s) {
    string new_str;

    bool flag = false;

    for (char c: s) {
        if (c == '_') {
            flag = true;
        } else {
            if (flag) {
                new_str.push_back(c + ('A' - 'a'));
                flag = false;
            } else {
                new_str.push_back(c);
            }
        }
    }

    return new_str;
}

string to_c_style(const string &s) {
    string new_str;

    for (char c: s) {
        if (c >= 'A' && c <= 'Z') {
            new_str.push_back('_');
            new_str.push_back(c - ('A' - 'a'));
        } else {
            new_str.push_back(c);
        }
    }

    return new_str;
}

int main_() {
    string s;
    cin >> s;

    if (is_java_style(s)) {
        cout << to_c_style(s) << endl;
    } else {
        if (is_c_style(s)) {
            cout << to_java_style(s) << endl;
        } else {
            cout << "Error!" << endl;
        }
    }

    return 0;
}