
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> q;
    for (int i = 1; i <= n; i++) q.push_back(i);

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int cnt = 0;

        deque<int> from_front = q;
        deque<int> from_back = q;
        int from_front_cnt = 0;
        int from_back_cnt = 0;

        while (from_front.front() != k) {
            from_front.pop_front();
            from_front_cnt++;
        }

        while (from_back.front() != k) {
            from_back.push_front(from_back.back());
            from_back.pop_back();
            from_back_cnt++;
        }

        if (from_front_cnt < from_back_cnt) {
            while (q.front() != k) {
                q.push_back(q.front());
                q.pop_front();
                cnt++;
            }
        } else {
            while (q.front() != k) {
                q.push_front(q.back());
                q.pop_back();
                cnt++;
            }
        }

        while (q.front() == k) {
            q.pop_front();
        }

        sum += cnt;
    }

    cout << sum << endl;

    return 0;
}