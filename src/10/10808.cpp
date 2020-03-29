#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int counts['z' - 'a' + 1] = {0};
    for (char c : s) counts[c - 'a']++;

    for (int count : counts) cout << count << " ";
    cout << endl;
}