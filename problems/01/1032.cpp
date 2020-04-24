#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names;
    names.reserve(n);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        names.push_back(name);
    }

    string sample = names[0];
    for (unsigned long long i = 0; i < sample.length(); i++) {
        bool flag = true;

        for (int j = 1; j < n; j++) {
            if (names[j][i] != sample[i]) {
                flag = false;
                break;
            }
        }

        if (!flag) sample[i] = '?';
    }

    cout << sample << endl;
}