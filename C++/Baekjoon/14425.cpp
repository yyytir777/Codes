#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
    int n, m;
    cin >> n >> m;
    
    string tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        s.insert(tmp);
    }

    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        if(s.find(tmp) != s.end()) cnt++;
    }

    cout << cnt;
}