/*
 * 미해결
 */


#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

struct Session {
    unsigned int start_time, end_time;

    Session(unsigned int start_time, unsigned int end_time) : start_time(start_time), end_time(end_time) {}

    Session() : Session(0, 0) {}

    void print() {
        cout << start_time << " ~ " << end_time << endl;
    }

    bool is_overlapped(Session &other) {
        if (start_time >= other.start_time && start_time < other.end_time) return true;
        if (start_time <= other.start_time && end_time > other.start_time) return true;
        if (start_time >= other.start_time && end_time <= other.end_time) return true;
        if (start_time <= other.start_time && end_time >= other.end_time) return true;
        return false;
    }

    void insert_to(vector<Session> &v) {
        stack<vector<Session>::iterator> to_erase;
        int i = 0;
        for (auto iter = v.begin(); iter != v.end(); iter++) {
            if (is_overlapped(*iter)) {
                to_erase.push(iter);
                i++;
            }
        }
        while (!to_erase.empty()) {
            v.erase(to_erase.top());
            to_erase.pop();
        }

        v.push_back(*this);
    }
};

int main() {
    int n;
    cin >> n;
    vector<Session> sessions(n);

    for (Session &s: sessions) {
        cin >> s.start_time >> s.end_time;
    }

    sort(sessions.begin(), sessions.end(), [](const Session &a, const Session &b) -> bool {
        if (a.end_time - a.start_time < b.end_time - b.start_time) return true;
        if (a.end_time - a.start_time > b.end_time - b.start_time) return false;
        if (a.start_time < b.start_time) return true;
        if (a.start_time > b.start_time) return false;
        return false;
    });

    vector<Session> active_sessions;
    unsigned int max_session_count = 0;

    for (Session &s: sessions) {
        s.insert_to(active_sessions);
        if (max_session_count < active_sessions.size()) max_session_count = active_sessions.size();
    }

    cout << max_session_count << endl;

    return 0;
}