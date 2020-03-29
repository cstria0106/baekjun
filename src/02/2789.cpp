#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    string cambridge = "CAMBRIDGE";
    for (char c : s) {
        if (cambridge.find(c) == string::npos) cout << c;
    }

    cout << endl;
}