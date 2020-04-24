#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int *a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        if (binary_search(a, a + n, b)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    delete[] a;
}