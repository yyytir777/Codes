#include <bits/stdc++.h>
using namespace std;

map<string, float> grade_map;

void init() {
    grade_map.insert({"A+", 4.5});
    grade_map.insert({"A0", 4.0});
    grade_map.insert({"B+", 3.5});
    grade_map.insert({"B0", 3.0});
    grade_map.insert({"C+", 2.5});
    grade_map.insert({"C0", 2.0});
    grade_map.insert({"D+", 1.5});
    grade_map.insert({"D0", 1.0});
    grade_map.insert({"F", 0.0});
}

int main() {
    init();

    string tmp;
    float classes;
    string grade;

    double sum = 0;
    int num_of_classes = 0;
    for(int i = 0; i < 20; i++) {
        cin >> tmp >> classes >> grade;
        if(grade == "P") continue;
        sum += grade_map[grade] * classes;
        num_of_classes += classes;
    }

    printf("%5f", sum / num_of_classes);
}