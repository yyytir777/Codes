// 2533 cpp
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n;
int edges[MAX] = {0,};
int dp[MAX][2];
vector<int> graph[MAX];

void input() {
  cin >> n;

  int u, v;
  for(int i = 1; i < n; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
    edges[u]++, edges[v]++;
  }
}

void dfs(int cur, int parent) {
  dp[cur][0] = 0;
  dp[cur][1] = 1;

  for(int i = 0; i < graph[cur].size(); i++) {
    int child = graph[cur][i];
    if(child == parent) continue;

    dfs(child, cur);

    dp[cur][0] += dp[child][1];
    dp[cur][1] += min(dp[child][0], dp[child][1]);
  }
}

void solve() {
  dfs(1, 0);
  cout << min(dp[1][1], dp[1][0]);
}

int main() {
  input();
  solve();
  return 0;
}