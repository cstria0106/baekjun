#include <iostream>
#include <string>
#include <vector>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

using namespace std;

int piece_to_repaint(const vector<string> &board, int x, int y) {
    int wb_count = 0;
    int bw_count = 0;

    for (int x_ = 0; x_ < 8; x_++) {
        for (int y_ = 0; y_ < 8; y_++) {
            int x__ = x + x_;
            int y__ = y + y_;

            if (y_ % 2 == 0) {
                if (x_ % 2 == 0) {
                    if (board[y__][x__] == 'W') {
                        bw_count++;
                    } else {
                        wb_count++;
                    }
                } else {
                    if (board[y__][x__] == 'W') {
                        wb_count++;
                    } else {
                        bw_count++;
                    }
                }
            } else {
                if (x_ % 2 == 0) {
                    if (board[y__][x__] == 'W') {
                        wb_count++;
                    } else {
                        bw_count++;
                    }
                } else {
                    if (board[y__][x__] == 'W') {
                        bw_count++;
                    } else {
                        wb_count++;
                    }
                }
            }
        }
    }

    return MIN(wb_count, bw_count);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> board(n);

    for (string &line: board) {
        cin >> line;
    }

    int min = n * m;
    for (int x = 0; x <= m - 8; x++) {
        for (int y = 0; y <= n - 8; y++) {
            int count = piece_to_repaint(board, x, y);
            if (min > count) min = count;
        }
    }

    cout << min << endl;

    return 0;
}