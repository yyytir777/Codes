#include <bits/stdc++.h>
using namespace std;

set<string> set_string;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            string tmp = "";
            for(int k = i; k <= j; k++) tmp += s[k];
            set_string.insert(tmp);
        }
    }

    cout << set_string.size() <<'\n';
    return 0;
}