#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i : v) {
        cin >> i;
    }

    stack<int> from_stack;
    for (int i = n; i >= 1; i--) from_stack.push(i);

    int i = 0;
    stack<int> to_stack;

    string print_str;
    while (!from_stack.empty()) {
        to_stack.push(from_stack.top());
        from_stack.pop();
        print_str += "+\n";
        while ((!to_stack.empty()) && (to_stack.top() == v[i])) {
            to_stack.pop();
            print_str += "-\n";
            i++;
        }
    }

    if (to_stack.empty()) {
        cout << print_str << endl;
    } else {
        cout << "NO" << endl;
    }

}