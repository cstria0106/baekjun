#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main_() {
    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> count(8001, 0);
    int sum = 0;
    int max_count = 0;
    vector<int> modes;

    for (int &i: v) {
        cin >> i;
        sum += i;
        count[i + 4000]++;
        if (max_count == count[i + 4000]) {
            modes.push_back(i);
        } else if (max_count < count[i + 4000]) {
            modes.clear();
            max_count = count[i + 4000];
            modes.push_back(i);
        }
    }

    sort(v.begin(), v.end());
    sort(modes.begin(), modes.end());

    int average = (int) (round((double) sum / n));
    int center = v[n / 2];
    int min = v[0];
    int max = v[n - 1];
    int range = max - min;
    int mode = (modes.size() > 1 ? modes[1] : modes[0]);

    cout << average << endl << center << endl << mode << endl << range << endl;

    return 0;
}
