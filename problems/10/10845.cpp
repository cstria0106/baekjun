#include<iostream>
#include<queue>
#include<string>
#include<map>

using namespace std;

enum Command {
    push,
    pop,
    size,
    empty,
    front,
    back,
};

map<string, Command> command_map{{"push",  push},
                                 {"pop",   pop},
                                 {"size",  size},
                                 {"empty", empty},
                                 {"front", front},
                                 {"back",  back}};

int main() {
    int command_length;

    cin >> command_length;

    queue<int> q;

    for (int i = 0; i < command_length; i++) {
        string command;
        cin >> command;

        switch (command_map[command]) {
            case push:
                int n;
                cin >> n;
                q.push(n);
                break;
            case pop:
                if (q.empty()) {
                    cout << "-1" << endl;
                    break;
                }
                cout << q.front() << endl;
                q.pop();
                break;
            case size:
                cout << q.size() << endl;
                break;
            case empty:
                cout << (q.empty() ? 1 : 0) << endl;
                break;
            case front:
                cout << (q.empty() ? -1 : q.front()) << endl;
                break;
            case back:
                cout << (q.empty() ? -1 : q.back()) << endl;
                break;
        }
    }
}