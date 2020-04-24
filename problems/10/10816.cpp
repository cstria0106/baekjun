/*
 * 미해결, 파이썬 딕셔너리로 해결
 */


#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> counts;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (counts.find(number) == counts.end()) counts[number] = 1;
        else counts[number]++;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int to_count;
        cin >> to_count;
        cout << counts[to_count] << " ";
    }
    cout << endl;

    return 0;
}