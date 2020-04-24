
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> times(n);
    for (int &time: times) cin >> time;

    sort(times.begin(), times.end());

    int sum = 0;
    int spend = 0;

    for (int &time: times) {
        spend += time;
        sum += spend;
    }

    cout << sum << endl;

    return 0;
}