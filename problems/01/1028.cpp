
#include <iostream>
#include <vector>

using namespace std;

class Mine {
private:
    vector<vector<bool>> data;
    int width, height;
    int deltas[2][2] = {{-1, 1},
                        {1,  1}};

    vector<vector<vector<int>>> lengths;

public:
    Mine(size_t width, size_t height) : width(width), height(height) {
        data = {height, vector<bool>(width, false)};
        lengths = {height, {width, vector<int>(2, -1)}};
    }

    void get_input() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                char input;
                cin >> input;
                data[y][x] = input == '1';
            }
        }
    }

    int check_length(int x, int y, int way) {
        if (x < 0 || x >= width || y < 0 || y >= height) return 0;
        if (data[y][x] == false) return 0;
        if (lengths[y][x][way] != -1) return lengths[y][x][way];
        lengths[y][x][way] = 1 + check_length(x + deltas[way][0], y + deltas[way][1], way);
        return lengths[y][x][way];
    }

    int check_diamond_size(int x, int y) {
        int size = check_length(x, y, 0);
        if (size == 0) return 0;

        for (; size > 1; size--) {
            if (size > check_length(x, y, 1)) continue;
            if (size > check_length(x - size + 1, y + size - 1, 1)) continue;
            if (size > check_length(x + size - 1, y + size - 1, 0)) continue;
            break;
        }

        return size;
    }

    int get_max_diamond_size() {
        int max = 0;
        for (int y = 0; y < height - 2 * max + 1; y++) {
            for (int x = 0; x < width - max; x++) {
                int diamond_size = check_diamond_size(x, y);
                if (max < diamond_size) max = diamond_size;
            }
        }

        return max;
    }
};

int main() {
    int r, c;
    cin >> r >> c;

    Mine mine(c, r);
    mine.get_input();
    cout << mine.get_max_diamond_size() << endl;

    return 0;
}