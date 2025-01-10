// 13023 cpp
#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

typedef pair<int, int> Pair;

int n, m;
int visited[MAX] = {0,};
bool flag = false;
vector<int> v[MAX];

void input() {
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void dfs(int num, int cnt) {
    if(cnt >= 4) {
        flag = true;
        return;
    }

    visited[num] = 1;
    for(int next : v[num]) {
        if(!visited[next]) dfs(next, cnt + 1);
    }

    visited[num] = 0;
}

void init_visited() {
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        dfs(i, 0);
        if(flag) {
            cout << "1";
            return;
        }
    }

    cout << "0";
    return;
}

int main() {
    input();
    solve();
    return 0;
}