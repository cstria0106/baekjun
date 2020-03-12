#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print_vector(vector<T> v) {
    cout << "<";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";
    }
    cout << ">" << endl;
}

int main() {
    int n, k;

    cin >> n;
    cin >> k;

    vector<int> table;
    table.reserve(n);

    for (int i = 1; i <= n; i++) {
        table.push_back(i);
    }

    vector<int> removed;

    int position = k - 1;

    while (!table.empty()) {
        print_vector(table);

        int index = position % table.size();
        removed.push_back(table[index]);
        table.erase(table.begin() + index);
        position += k - 1;
    }

    print_vector(removed);
}