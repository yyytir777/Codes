#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX] = {0,};
int dp[MAX];
int n, r, q;

void dfs(int start) {
    visited[start] = 1;
    dp[start] = 1;

    for(int adj : graph[start]) {
        if(visited[adj]) continue;
        dfs(adj);
        dp[start] += dp[adj];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r >> q;

    int u, v;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r);

    for(int i = 0; i < q; i++) {
        cin >> u;
        cout << dp[u] << '\n';
    }
}