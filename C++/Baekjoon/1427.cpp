#include <bits/stdc++.h>
using namespace std;

bool compare(char a, char b) {
    return a > b ? true : false;
}

int main() {
    string n;
    cin >> n;

    vector<char> v;
    for(int i = 0; i < n.size(); i++) {
        v.push_back(n[i]);
    }

    sort(v.begin(), v.end(), compare);
    for(char letter : v) {
        cout << letter;
    }
}