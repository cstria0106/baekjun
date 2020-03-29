#include <iostream>
#include <string>
#include <vector>

using namespace std;

string explode(const string &src, const string &explosive) {
    vector<char> stack;
    stack.reserve(src.size());

    for (char c : src) {
        stack.push_back(c);
        if (stack.size() >= explosive.length()) {
            bool flag = true;
            for (size_t i = 0; i < explosive.length(); i++) {
                if (*(stack.end() - explosive.length() + i) != explosive[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (size_t i = 0; i < explosive.length(); i++) {
                    stack.pop_back();
                }
            }
        }
    }

    stack.push_back('\0');
    return string(stack.data());
}

int main() {
    string str, exp;
    cin >> str >> exp;

    string exploded = explode(str, exp);

    if (exploded.empty()) cout << "FRULA";
    else cout << exploded;
}