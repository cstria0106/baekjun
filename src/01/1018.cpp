/**
 * 미해결
 */

#include <iostream>
#include <cstdio>

using namespace std;

int piece_to_repaint(char **board, int left_top_x, int left_top_y, int size) {
    int bw = 0;
    int wb = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int real_x = x + left_top_x;
            int real_y = y + left_top_y;
            if (x % 2 == y % 2) {
                if (board[real_y][real_x] == 'W') bw++;
                if (board[real_y][real_x] == 'B') wb++;
            } else {
                if (board[real_y][real_x] == 'W') wb++;
                if (board[real_y][real_x] == 'B') bw++;
            }
        }
    }

    return bw > wb ? wb : bw;
}

int main() {
    int w, h;

    cin >> h >> w;

    char **board = new char *[h];
    for (int i = 0; i < h; i++) {
        board[i] = new char[h];
    }

    // clear buffer
    getchar();

    for (int y = 0; y < h; y++) {
        scanf("%s", board[y]);
    }

    int min = 0;
    for (int y = 0; y <= h - 8; y++) {
        for (int x = 0; x <= w - 8; x++) {
            int pieces = piece_to_repaint(board, x, y, 8);
            if (x == 0 && y == 0) min = pieces;
            else {
                if (min > pieces) min = pieces;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        delete board[i];
    }

    delete[] board;

    cout << min;
}