#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <chrono>
#include "main.h"

#define NUMBER 1028 // 문제 번호

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define INPUT "../test/input/" STR(NUMBER) ".txt"
#define OUTPUT "../test/output/" STR(NUMBER) ".txt"

#define USE_TEST_CASE_

using namespace std;

int main() {
#ifdef USE_TEST_CASE
    // 표준 출력 버퍼 저장
    streambuf *std_out_buffer = std::cout.rdbuf();

    ifstream input_file_stream(INPUT);
    ifstream output_file_stream(OUTPUT);

    if (!input_file_stream.is_open()) {
        cout << "No input file." << endl;
        return 0;
    }

    if (!output_file_stream.is_open()) {
        cout << "No output file." << endl;
        return 0;
    }

    vector<string> inputs = get_cases(input_file_stream);
    cout << "Inputs: " << inputs.size() << endl;

    vector<string> outputs = get_cases(output_file_stream);
    cout << "Outputs: " << outputs.size() << endl;

    if (inputs.size() != outputs.size()) {
        cout << "Input count is not equal to output count." << endl;
        return 0;
    }

    int score = 0;
    set<int> wrong_set;
    vector<string> real_outputs;
    vector<int> times;
#endif
    int ret = 0;
#ifdef USE_TEST_CASE
    for (size_t i = 0; i < inputs.size(); i++) {
        string &input = inputs[i];
        string &expected = outputs[i];

        stringstream input_string_stream(input);
        cin.rdbuf(input_string_stream.rdbuf()); // 입력 버퍼 교체

        stringstream output_string_stream;
        cout.rdbuf(output_string_stream.rdbuf()); // 출력 버퍼 교체

        chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif
        ret = main_();
#ifdef USE_TEST_CASE
        chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        times.push_back(chrono::duration_cast<chrono::milliseconds>(end - begin).count());

        cout.rdbuf(std_out_buffer);
        string result = output_string_stream.str();
        real_outputs.push_back(result);

        string result_trimmed = result;
        string expected_trimmed = expected;
        ltrim(result_trimmed);
        rtrim(result_trimmed);
        ltrim(expected_trimmed);
        rtrim(expected_trimmed);

        if (result_trimmed == expected_trimmed) score++;
        else wrong_set.insert(i);
    }

    int max_time = times[0];
    for (auto time: times) if (max_time < time) max_time = time;

    if (score == inputs.size()) {
        cout << "You passed all test cases." << endl << "Max duration: " << max_time << "ms" << endl;
    } else {
        cout << "You passed " << score << " cases out of " << inputs.size() << endl;
        for (int i: wrong_set) {
            cout << endl << "[Case #" << i << "]" << endl;
            cout << "[Input]" << endl;
            cout << inputs[i];
            cout << "[Expected Output]" << endl;
            cout << outputs[i];
            cout << "[Output]" << endl;
            cout << real_outputs[i];
            cout << "[Time]" << endl;
            cout << times[i] << "ms" << endl;
        }
    }
#endif

    return ret;
}
