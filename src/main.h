#ifndef BAEKJUN_MAIN_H
#define BAEKJUN_MAIN_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

static vector<string> get_cases(ifstream &in) {
    vector<string> cases;

    string case_string;
    string line;
    while (getline(in, line)) {
        if (line == "~~~~") {
            cases.push_back(case_string);
            case_string = "";
            continue;
        }
        case_string += line + "\n";
    }
    if (!case_string.empty()) cases.push_back(case_string);
    return cases;
}

int main_();

#endif //BAEKJUN_MAIN_H
