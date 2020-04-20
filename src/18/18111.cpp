/**
 * 미해결
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Minecraft {
    int width, height;
    int block_in_hand;
    vector<short> blocks;


public:
    Minecraft(int width, int height, int block_amount) : width(width), height(height), block_in_hand(block_amount) {}

    int top() {
        return blocks[0];
    }

    int get_fill_time() {
        short top = blocks[0];
        int used_blocks = 0;
        for (short block: blocks) {
            used_blocks += top - block;
            if (used_blocks > block_in_hand) return width * height * 3;
        }
        return used_blocks * 1;
    }

    int get_dig_time() {
        short top = blocks[0];
        if (top == 0) return width * height * 3;
        int dug_blocks = 0;
        for (short block: blocks) {
            if (block == top) dug_blocks++;
        }
        return dug_blocks * 2;
    }

    void fill() {
        short top = blocks[0];
        for (short &block: blocks) {
            block_in_hand -= top - block;
            block = top;
        }
    }

    void dig() {
        short top = blocks[0];
        for (short &block: blocks) {
            if (block == top) {
                block--;
                block_in_hand++;
            }
        }
    }

    bool is_flat() {
        short sample = blocks[0];
        for (short block: blocks) {
            if (block != sample) return false;
        }
        return true;
    }

    int get_flatten_time() {
        int time = 0;

        while (!is_flat()) {
            int fill_time = get_fill_time();
            int dig_time = get_dig_time();

            if (fill_time <= dig_time) {
                fill();
                time += fill_time;
            } else {
                dig();
                time += dig_time;
            }
        }
        return time;
    }

    void init_ground() {
        blocks.resize(width * height);
        for (short &block: blocks) {
            cin >> block;
        }

        sort(blocks.begin(), blocks.end(), greater<>());
    }
};

int main_() {
    int n, m, b;
    cin >> n >> m >> b;
    Minecraft minecraft(m, n, b);
    minecraft.init_ground();
    cout << minecraft.get_flatten_time() << " " << minecraft.top() << endl;

    return 0;
}