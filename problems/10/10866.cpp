#include<iostream>
#include<deque>
#include<string>
#include<map>


using namespace std;

enum Command {
    push_front,
    push_back,
    pop_front,
    pop_back,
    size,
    empty,
    front,
    back,
};

map<string, Command> command_map{{"push_front", push_front},
                                 {"push_back",  push_back},
                                 {"pop_front",  pop_front},
                                 {"pop_back",   pop_back},
                                 {"size",       size},
                                 {"empty",      empty},
                                 {"front",      front},
                                 {"back",       back}};

int main() {
    int command_length;

    cin >> command_length;

    deque<int> q;

    for (int i = 0; i < command_length; i++) {
        string command;
        cin >> command;

        int n;
        switch (command_map[command]) {
            case push_front:
                cin >> n;
                q.push_front(n);
                break;
            case push_back:
                cin >> n;
                q.push_back(n);
                break;
            case pop_front:
                if (q.empty()) {
                    cout << "-1" << endl;
                    break;
                }
                cout << q.front() << endl;
                q.pop_front();
                break;
            case pop_back:
                if (q.empty()) {
                    cout << "-1" << endl;
                    break;
                }
                cout << q.back() << endl;
                q.pop_back();
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
