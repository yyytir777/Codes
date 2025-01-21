// 2252 cpp
#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int n, m;
int degree[MAX] = {0,};
vector<int> v[MAX];
vector<int> ans;
queue<int> q;

void input() {
    cin >> n >> m;

    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(int j = 0; j < v[node].size(); j++) {
            int nxt_node = v[node][j];
            if(--degree[nxt_node] == 0) q.push(nxt_node);
        }
    }

    for(int element : ans) {
        cout << element << " ";
    }
}

int main() {
    input();
    solve();
    return 0;
}