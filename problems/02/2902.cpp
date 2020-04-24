#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    for (char c : s)if (c >= 'A' && c <= 'Z') cout << c;
}