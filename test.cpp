// 1325 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n, m;
vector<int> parent[MAX];
queue<int> q;
bool visited[MAX] = {0,};

void input() {
  cin >> n >> m;

  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    parent[b].push_back(a);
  }
}

void init() {
  for(int i = 1; i <= n; i++) visited[i] = 0;
}

int bfs(int start) {
  int cnt = 0;
  q.push(start);
  visited[start] = 1;

  while(!q.empty()) {
    int cur_node = q.front();
    q.pop();

    for(int i = 0; i < parent[cur_node].size(); i++) {
      int next_node = parent[cur_node][i];
      if(visited[next_node]) continue;
      q.push(next_node);
      visited[next_node] = 1;
      cnt++;
    }
  }
  return cnt;
}

void solve() {
  int max_result = 0;
  vector<int> results;
  for(int i = 0; i < n; i++) {
    init();
    int cnt = bfs(i+1);
    if(max_result < cnt) {
      max_result = cnt;
      results.clear();
      results.push_back(i+1);
    }
    else if(max_result == cnt) {
      results.push_back(i+1);
    }
  }

  for(auto node : results) {
    cout << node << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}