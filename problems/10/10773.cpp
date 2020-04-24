#include<iostream>
#include<stack>

using namespace std;

int main() {
    int k;
    cin >> k;

    stack<int> book;

    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;

        if (input == 0) book.pop();
        else book.push(input);
    }

    int sum = 0;
    while (!book.empty()) {
        sum += book.top();
        book.pop();
    }

    cout << sum << endl;
}