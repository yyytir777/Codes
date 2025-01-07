// 2493 cpp
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

typedef pair<int, int> Pair;

int n;
int t[MAX];
stack<Pair> s;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {

        if(s.empty()) {
            s.push({t[i], i});
            cout << "0 ";
        }
        else {
            while(!s.empty()) {
                if(s.top().first > t[i]) {
                    cout << s.top().second << " ";
                    break;
                }
                else {
                    s.pop();
                }
            }

            if(s.empty()) cout << "0 ";
            s.push({t[i], i});
        }
    }
}

int main() {
    input();
    solve();
    return 0;
}