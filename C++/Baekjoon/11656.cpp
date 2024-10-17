#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
    string tmp;
    cin >> tmp;

    for(int i = 0; i <= tmp.size(); i++) {
        string suffix = "";
        for(int j = 0; j < tmp.size() && j <= i; j++) {
            suffix = tmp[tmp.size() - j] + suffix;
        }
        v.push_back(suffix);
    }

    sort(v.begin(), v.end());

    for(string word : v) cout << word << '\n';
}