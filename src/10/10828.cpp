#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

enum Command {
    push,
    pop,
    size,
    empty,
    top,
};

map<string, Command> command_map{{"push",  push},
                                 {"pop",   pop},
                                 {"size",  size},
                                 {"empty", empty},
                                 {"top",   top}};

int main() {
    int command_length;

    cin >> command_length;

    stack<int> s;

    for (int i = 0; i < command_length; i++) {
        string command;
        cin >> command;

        switch (command_map[command]) {
            case push:
                int n;
                cin >> n;
                s.push(n);
                break;
            case pop:
                if (s.empty()) {
                    cout << "-1" << endl;
                    break;
                }
                cout << s.top() << endl;
                s.pop();
                break;
            case size:
                cout << s.size() << endl;
                break;
            case empty:
                cout << (s.empty() ? 1 : 0) << endl;
                break;
            case top:
                cout << (s.empty() ? -1 : s.top()) << endl;
                break;
        }
    }
}