#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int count = 0;
    for (int i = 1; i <= 5; i++) {
        string name;
        cin >> name;
        if (name.find("FBI") != string::npos) {
            cout << i << endl;
            count++;
        }
    }
    if (count == 0) cout << "HE GOT AWAY!" << endl;
}