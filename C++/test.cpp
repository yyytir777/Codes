#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
    string name;
    int radius;
public:
    Circle(int radius = 1, string name = "") : radius(radius), name(name) {}
    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
    bool operator<(const Circle& b);
    friend ostream& operator<<(ostream& os, const vector<Circle>& b);
};

bool Circle::operator<(const Circle& b) {
    return radius < b.radius;
}

ostream& operator<<(ostream& os, const vector<Circle>& b) {
    for (const auto& circle : b) {
        os << circle.getName() << " ";
    }
    return os;
}

void printVector(const vector<Circle>& v) {
    cout << "모든 원소를 출력한다.>>";
    for (const auto& circle : v) {
        cout << circle.getName() << " ";
    }
    cout << endl;
}

int main() {
    vector<Circle> v;
    v.push_back(Circle(2, "waffle"));
    v.push_back(Circle(3, "pizza"));
    v.push_back(Circle(1, "dotnet"));
    v.push_back(Circle(5, "pizzsLarge"));
    printVector(v);

    int it = v.size() - 1;
    sort(v.begin(), v.end());
    printVector(v);

    cout << endl << "프랜드 함수 operator <<로 출력하는 경우" << endl;
    cout << v << endl;
   
    return 0;
}
