
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        vector<int> numbers;
        numbers.push_back(a % 10);

        int root = (a * a) % 10;
        while (numbers[0] != root) {
            numbers.push_back(root);
            root = (int) (root * a) % 10;
        }

        int last = numbers[(b - 1) % numbers.size()];
        cout << (last == 0 ? 10 : last) << endl;
    }
    return 0;
}