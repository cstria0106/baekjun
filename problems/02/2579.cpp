#include <iostream>
#include <vector>

using namespace std;

int max_scores[301][2] = {0};
int scores[301] = {0};

int get_max_score(int n, bool combo) {
    if (n == 0) return 0;
    if (n == 1) return scores[n];

    int score;
    if (max_scores[n][combo] != 0) return max_scores[n][combo];

    if (!combo) {
        score = scores[n] + get_max_score(n - 1, true);
        if (max_scores[n][combo] < score) {
            max_scores[n][combo] = score;
        }

        score = scores[n] + get_max_score(n - 2, false);
        if (max_scores[n][combo] < score) {
            max_scores[n][combo] = score;
        }

        return max_scores[n][combo];
    }

    max_scores[n][combo] = scores[n] + get_max_score(n - 2, false);
    return max_scores[n][combo];
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> scores[i];
    }

    max_scores[1][true] = max_scores[1][false] = scores[1];

    int score_a = get_max_score(n, false);
    int score_b = get_max_score(n, true);
    int max = (score_a > score_b ? score_a : score_b);

    cout << max << endl;
}