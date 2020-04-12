#include "../main.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define LINE_WIDTH 80

using namespace std;

int main_() {
    vector<string> words;
    while (!cin.eof()) {
        char word[LINE_WIDTH + 1];
        cin >> word;
        words.emplace_back(word);
    }
    words.pop_back();

    vector<string> lines(1);
    for (string &word: words) {
        if (word == "<br>") {
            lines.emplace_back("");
            continue;
        }
        if (word == "<hr>") {
            if (lines.back().length() != 0) {
                lines.emplace_back("");
            }
            lines.back() = string(80, '-');
            lines.emplace_back("");
            continue;
        }
        if (lines.back().length() + word.length() + 1 > 80) {
            lines.emplace_back("");
        }

        if (lines.back().length() != 0) word = " " + word;
        lines.back() += word;
    }

    for (string &line: lines) {
        cout << line << endl;
    }


    return 0;
}