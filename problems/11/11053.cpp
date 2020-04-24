/*
 * 미해결
 */

#include <iostream>

using namespace std;

int array[1000];
int n;

int get_lis(int from) {

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << get_lis(0) << endl;
}