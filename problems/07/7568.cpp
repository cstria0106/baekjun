#include <iostream>
#include <vector>

using namespace std;

struct Person {
    int weight, height, point;
};

int main() {
    int n;
    cin >> n;

    vector<Person> people(n);
    for (Person &p: people) {
        cin >> p.weight >> p.height;
        p.point = 0;
    }

    for (Person &p: people) {
        for (Person &other: people) {
            if (&p != &other) {
                if (p.weight < other.weight && p.height < other.height) {
                    p.point++;
                }
            }
        }
    }

    for (const Person &person: people) {
        cout << person.point + 1 << " ";
    }

    cout << endl;


    return 0;
}