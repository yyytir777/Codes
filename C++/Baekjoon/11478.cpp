#include <bits/stdc++.h>
using namespace std;

set<string> set_string;

int main() {
    string s;
    cin >> s;

    for(int i = 1; i <= s.size(); i++) {
        for(int j = 0; j <= s.size() - i; j++) {
            string tmp = "";
            for(int k = 1; k <= i; k++) {
                tmp += s[j + k - 1];
            }
            set_string.insert(tmp);
        }
    }

    cout << set_string.size() <<'\n';
    return 0;
}