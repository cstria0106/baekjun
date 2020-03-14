/**
 * 미해결
 */
#include<iostream>
#include<algorithm>

using namespace std;

class Topic {
public:
    int teacher;
    int student;

    Topic(int teacher, int student) {
        this->teacher = teacher;
        this->student = student;
    }

    Topic() {
        this->teacher = 0;
        this->student = 0;
    }

    bool is_good_pair(const Topic &other) {
        return this->teacher + other.teacher > this->student + other.student;
    }
};

int main() {
    int n;
    cin >> n;

    auto *topics = new Topic[n];

    for (int i = 0; i < n; i++) cin >> topics[i].teacher;
    for (int i = 0; i < n; i++) cin >> topics[i].student;

    auto sorted_by_teacher = new Topic[n];
    auto sorted_by_student = new Topic[n];

    copy(topics, topics + n, sorted_by_teacher);
    copy(topics, topics + n, sorted_by_student);

    sort(sorted_by_teacher, sorted_by_teacher + n, [](const Topic &a, const Topic &b) -> bool {
        return a.teacher > b.teacher;
    });
    sort(sorted_by_student, sorted_by_student + n, [](const Topic &a, const Topic &b) -> bool {
        return a.student < b.student;
    });

    for_each(sorted_by_teacher, sorted_by_teacher + n, [](Topic t) -> void {
        cout << t.teacher << ", " << t.student << "\n";
    });

    int good_topic_count = 0;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        Topic &left_topic = sorted_by_teacher[left];
        Topic &right_topic = sorted_by_teacher[right];

        if (&left_topic != &right_topic) {
            if (left_topic.is_good_pair(right_topic)) {
                good_topic_count++;
                left++;
            } else {
                break;
            }
        } else {
            left++;
            right--;
        }
    }

    cout << good_topic_count;

    delete[] topics;
}