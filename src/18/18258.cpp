#include<cstdio>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

enum Command {
    push,
    pop,
    size,
    empty,
    front,
    back,
};

unordered_map<string, Command> command_map{{"push",  push},
                                           {"pop",   pop},
                                           {"size",  size},
                                           {"empty", empty},
                                           {"front", front},
                                           {"back",  back}};

int main() {
    int command_length;

    scanf("%d", &command_length);

    queue<int> q;

    for (int i = 0; i < command_length; i++) {
        char command_cstr[6];
        scanf("%s", command_cstr);
        string command(command_cstr);

        switch (command_map[command]) {
            case push:
                int n;
                scanf("%d", &n);
                q.push(n);
                break;
            case pop:
                if (q.empty()) {
                    printf("-1\n");
                    break;
                }
                printf("%d\n", q.front());
                q.pop();
                break;
            case size:
                printf("%d\n", q.size());
                break;
            case empty:
                printf("%d\n", (q.empty() ? 1 : 0));
                break;
            case front:
                printf("%d\n", (q.empty() ? -1 : q.front()));
                break;
            case back:
                printf("%d\n", (q.empty() ? -1 : q.back()));
                break;
        }
    }
}