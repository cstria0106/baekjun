#include <iostream>
#include <string>

using namespace std;

string decrypt(const string &cipher) {
    string plain = cipher;

    for (char &c: plain) {
        int pos = ((c - 'A') - 3) % ('Z' - 'A');
        if (pos < 0) pos += 'Z' - 'A' + 1;
        c = (char) ('A' + pos);
    }

    return plain;
}

int main() {
    string cipher;
    cin >> cipher;

    string plain = decrypt(cipher);
    cout << plain;
}