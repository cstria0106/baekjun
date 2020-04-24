/*
 * 미해결
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Command {
    enum CommandType {
        Type,
        Undo
    };

    CommandType type;
    string argument;
    unsigned long long time;
    string before;
};

int main() {
    int n;
    cin >> n;

    vector<Command> commands(n);
    for (auto &command: commands) {
        string type;
        cin >> type;
        if (type == "type") command.type = Command::Type;
        else if (type == "undo") command.type = Command::Undo;
        cin >> command.argument >> command.time;
    }

    string buffer;
    for (auto &command: commands) {
        command.before = buffer;
        switch (command.type) {
            case Command::Type:
                buffer += command.argument;
                break;
            case Command::Undo:
                unsigned long long undo_time = strtoull(command.argument.c_str(), nullptr, 10);
                for (auto &history : commands) {
                    if (history.time >= command.time - undo_time) {
                        buffer = history.before;
                        break;
                    }
                }
        }
    }

    cout << buffer << endl;

    return 0;
}