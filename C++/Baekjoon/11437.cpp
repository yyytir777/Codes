// 11437 cpp
#include <bits/stdc++.h>
#define MAX 50001
using namespace std;

typedef pair<int, int> Pair;

int n, m;
vector<int> graph[MAX];
int depth[MAX];
int parent[MAX];

void solve(Pair node) {
  int a = node.first;
  int b = node.second;

  while(depth[a] > depth[b]) {
    a = parent[a];
  }

  while(depth[b] > depth[a]) {
    b = parent[b];
  }

  if(a == b) {
    cout << a << '\n';
    return;
  }

  while(parent[a] != parent[b]) {
    a = parent[a]; b = parent[b];
  }

  cout << parent[a] << '\n';
}

void dfs(int cur_node, int parent_node, int depth_level) {
  parent[cur_node] = parent_node;
  depth[cur_node] = depth_level;

  for(auto node : graph[cur_node]) {
    if(node != parent_node) {
      dfs(node, cur_node, depth_level + 1);
    }
  }
}

void input() {
  cin >> n;

  int tmp1, tmp2;
  for(int i = 1; i < n; i++) {
    cin >> tmp1 >> tmp2;
    graph[tmp1].push_back(tmp2);
    graph[tmp2].push_back(tmp1);
  }

  dfs(1, 0, 0);

  cin >> m;
  int start, end;
  for(int i = 0; i < m; i++) {
    cin >> start >> end;
    solve({start, end});
  }
}

int main() {
  input();
  return 0;
}