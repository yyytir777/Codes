#include <bits/stdc++.h>
using namespace std;

string str;

bool solve() {
    int len = str.length();
    for(int i = 0; i <= str.length() / 2; i++) {
        if(str[i] != str[len - i - 1]) return false;
    }
    return true;
}

int main() {
    cin >> str;
    bool flag = solve();
    if(flag) cout << "1";
    else cout << "0";
    return 0;
}