/**
 * 미해결
 */
#include <iostream>

using namespace std;

bool is_palindrome(int *array, int start, int length) {
    int end = start + length - 1;

    int left = start;
    int right = end;

    bool flag = false;
    while (left < right) {
        cout << "[" << left << ", " << right << "]" << endl;
        if (array[left] != array[right]) {
            if (flag) return false;
            right--;
            if (left == right) return false;
        } else {
            flag = true;
            left++;
            right--;
        }
    }

    cout << "[" << left << ", " << right << "]" << endl;
    cout << "end!" << endl;
    return left <= right;
}

bool is_palindrome(int *array, int length) {
    int check_length = 3;

    while (check_length <= length) {
        for (int start = 0; start <= length - check_length; start++) {
            if (is_palindrome(array, start, check_length)) return true;
        }

        check_length++;
    }

    return false;
}

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int length;
        cin >> length;

        auto array = new int[length];

        for (int j = 0; j < length; j++) {
            cin >> array[j];
        }

        cout << (is_palindrome(array, length) ? "YES" : "NO") << endl;

        delete[] array;
    }
}