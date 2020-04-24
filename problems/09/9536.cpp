#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    int t;
    cin >> t;

    cin.ignore();

    for (int i = 0; i < t; i++) {
        vector<string> sounds;
        vector<string> not_fox_sounds;

        string sounds_str;
        sounds_str.reserve(10000);

        getline(cin, sounds_str);

        stringstream ss;
        ss << sounds_str;

        string sound;

        while (ss >> sound) {
            sounds.push_back(sound);
        }

        while (true) {
            getline(cin, sounds_str);
            if (sounds_str == "what does the fox say?") break;
            ss.clear();
            ss << sounds_str;
            ss >> sound;
            ss >> sound;
            ss >> sound;
            not_fox_sounds.push_back(sound);
        }

        sort(not_fox_sounds.begin(), not_fox_sounds.end());

        for (string &s: sounds) {
            if (!binary_search(not_fox_sounds.begin(), not_fox_sounds.end(), s)) {
                cout << s << " ";
            }
        }

    }


}