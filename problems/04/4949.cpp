#include <iostream>
#include <stack>

using namespace std;

bool is_balanced(const string &s) {
    stack<char> stack;
    for (char c: s) {
        if (c == '[') stack.push('[');
        if (c == ']') {
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
        }
        if (c == '(') stack.push('(');
        if (c == ')') {
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    string s;
    s.reserve(101);
    while (true) {
        char cstr[101];
        cin.getline(cstr, 101);
        s = cstr;
        if (s == ".") break;
        else if (is_balanced(s)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}