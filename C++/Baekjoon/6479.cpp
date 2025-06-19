// 6479 cpp
#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

typedef unsigned long long ll;
typedef pair<ll, pair<int, int>> Edge;
typedef pair<int, ll> Pair;

int n, m;
ll sum, total_sum;
vector<pair<int, int>> v[MAX];
priority_queue<Edge> pq;
bool visited[MAX] = {0,};

void init() {
  total_sum = 0;
  for(int i = 0; i < m; i++) {
    visited[i] = 0;
    v[i].clear();
  }

  while(!pq.empty()) {
    pq.pop();
  }
}

void input() {
  init();

  int x, y;
  ll z;
  for(int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    v[x].push_back({y,z});
    v[y].push_back({x,z});
    total_sum += z;
  }
}

void solve() {
  int start = 0, node_cnt = 0;
  sum = 0;
  visited[start] = 1;

  for(Pair pair : v[start]) 
    pq.push({-pair.second, {start, pair.first}});

  while(node_cnt < m - 1) {
    Edge edge = pq.top();
    int next_node = edge.second.second;
    pq.pop();

    if(visited[next_node]) continue;
    visited[next_node] = 1;
    node_cnt++;
    sum += -edge.first;

    for(Pair pair : v[next_node]) {
      if(visited[pair.first]) continue;
      pq.push({-pair.second, {next_node, pair.first}});
    }
  }
  cout << total_sum - sum << "\n";
}

int main() {
  while(true) {
    cin >> m >> n;
    if(n == 0 && m == 0) break;
    input();
    solve();
  }
  return 0;
}