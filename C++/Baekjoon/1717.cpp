// 1717 cpp
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, m;
int parent[MAX];

void init_parent() {
    for(int i = 0; i <= n; i++) parent[i] = i;
}

int getParent(int n) {
    if(parent[n] == n) return n;

    return getParent(parent[n]);
}

void merge(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a == b) return;

    if(a > b) parent[b] = a;
    else parent[a] = b;
}

void input() {
    cin >> n >> m;
}

void solve() {
    init_parent();

    int flag, a, b;
    for(int i = 0; i < m; i++) {
        cin >> flag >> a >> b;

        if(!flag) {
            merge(a,b);
        }
        else {
            if(getParent(a) == getParent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    solve();
    return 0;
}