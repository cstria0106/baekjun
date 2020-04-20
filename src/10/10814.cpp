#include<cstdio>
#include<vector>
#include "../main.h"

using namespace std;

class User {
public:
    int age;
    char name[101];
};

int main_() {
    int n;
    scanf("%d", &n);

    vector<vector<User>> users(201);

    for (int i = 0; i < n; i++) {
        User user = {};
        scanf("%d %s", &user.age, user.name);
        users[user.age].push_back(user);
    }

    for (int i = 1; i <= 200; i++) {
        for (const User &user: users[i]) {
            printf("%d %s\n", user.age, user.name);
        }
    }

    return 0;
}