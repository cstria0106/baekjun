/**
 * 미해결
 */

#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

class User {
public:
    int age;
    string name;
};

int main() {
    int n;
    cin >> n;

    vector<User> users;
    users.reserve(n);

    for (int i = 0; i < n; i++) {
        User user;
        cin >> user.age >> user.name;
        users.push_back(user);
    }

    sort(users.begin(), users.end(), [](const User &a, const User &b) -> bool {
        return a.age < b.age;
    });

    for (const User &user: users) {
        printf("%d %s\n", user.age, user.name.c_str());
    }
}