#include <iostream>
#include <string>

using namespace std;

int get_time(char c) {
    char temp = c;
    if (c >= 'S') temp--;
    if (c >= 'Z') temp--;
    int time = 3 + ((temp - 'A') / 3);

    return time;
}

int main() {
    string word;
    cin >> word;

    int time = 0;
    for (char c: word) {
        time += get_time(c);
    }

    cout << time << endl;
}