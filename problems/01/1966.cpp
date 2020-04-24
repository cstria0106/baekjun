#include <iostream>
#include <queue>
#include <vector>


using namespace std;

bool is_max(queue<int> q, vector<int> priorities, int max_priority) {
    while (!q.empty()) {
        if (priorities[q.front()] > max_priority) return false;
        q.pop();
    }

    return true;
}

void print_queue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, curious;
        cin >> n >> curious;

        queue<int> q;
        vector<int> priorities(n);
        for (int j = 0; j < n; j++) {
            q.push(j);
            cin >> priorities[j];
        }

        int printed = 0;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            if (is_max(q, priorities, priorities[front])) {
                printed++;
                if (front == curious) {
                    cout << printed << endl;
                    break;
                }
            } else {
                q.push(front);
            }
        }
    }

    return 0;
}