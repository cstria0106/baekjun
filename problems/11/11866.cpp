#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i + 1);

    vector<int> deleted;
    int nth = 0;
    int i = 0;
    while (!v.empty()) {
        nth += k - 1;
        while (nth >= v.size()) nth -= v.size();
        auto iter = v.begin() + nth;
        deleted.push_back(*iter);
        v.erase(iter);
    }

    cout << "<";
    for (size_t j = 0; j < deleted.size(); j++) {
        cout << deleted[j];
        if (j != deleted.size() - 1) {
            cout << ", ";
        }
    }

    cout << ">" << endl;
}