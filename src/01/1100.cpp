#include <iostream>
#include <string>

using namespace std;

int main() {
    int count = 0;
    for (int y = 0; y < 8; y++) {
        string line;
        cin >> line;

        for (int x = (y % 2 == 0 ? 0 : 1); x < 8; x += 2) if (line[x] == 'F') count++;
    }

    cout << count << endl;
}