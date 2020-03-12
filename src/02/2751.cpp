#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v;
    v.reserve(n);

    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for_each(v.begin(), v.end(), [](int i) -> void {
        printf("%d\n", i);
    });
}
