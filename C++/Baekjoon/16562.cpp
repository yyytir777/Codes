// 16562 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

typedef pair<int, int> Pair;

int n, m, k;
bool visited[MAX];
Pair parent[MAX];

int getParent(int idx) {
  if(parent[idx].first == idx) return idx;
  return parent[idx].first = getParent(parent[idx].first);
}

void merge(int a, int b) {
  int rootA = getParent(a);
  int rootB = getParent(b);

  if (rootA == rootB) return;

  if (parent[rootA].second < parent[rootB].second) {
    parent[rootB] = {rootA, parent[rootA].second};
  } 
  else {
    parent[rootA] = {rootB, parent[rootB].second};
  }
}

void input() {
  cin >> n >> m >> k;

  int money;
  for(int i = 1; i <= n; i++) {
    cin >> money;
    parent[i] = {i, money};
  }

  int a, b;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    merge(a, b);
  }
}

bool isCycle(int a, int b) {
  return getParent(a) == getParent(b);
}

void solve() {
  int sum_cost = 0;
  for(int i = 1; i <= n; i++) {
    Pair parent_node = parent[getParent(i)];
    if(isCycle(0, parent_node.first)) continue;

    if(sum_cost + parent_node.second <= k) {
      sum_cost += parent_node.second;
      merge(0, parent_node.first);
    } 
    else {
      cout << "Oh no";
      return;
    }
  }
  cout << sum_cost;
}

int main() {
  input();
  solve();
  return 0;
}