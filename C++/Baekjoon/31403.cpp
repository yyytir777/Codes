#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a + b - c << '\n';
    string tmp =  to_string(a) + to_string(b);
    int result = stoi(tmp) - c;
    cout << result << '\n';
}