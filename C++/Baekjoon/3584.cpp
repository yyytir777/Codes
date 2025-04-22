// 3584 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
int s, e;
bool visited[MAX] = {0,};
int parent[MAX] = {0,};

void input() {
  cin >> n;

  for(int i = 1; i < n; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    parent[tmp2] = tmp1;
  }

  cin >> s >> e;
}

void print() {
  for(int i = 1; i <= n; i++) cout << parent[i] << " ";
  cout << '\n';
}

int findMaxParent() {
  int node_start = s;
  int node_end = e;
  visited[node_start] = 1;

  while(parent[node_start] != 0) {
    node_start = parent[node_start];
    visited[node_start] = 1;
  }

  while(!visited[node_end]) {
    visited[node_end] = 1;
    node_end = parent[node_end];
  }

  return node_end;
}

void solve() {
  cout << findMaxParent() << '\n';
}

void init() {
  for(int i = 1; i <= MAX; i++) {
    visited[i] = 0;
    parent[i] = 0;
  }
}

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    init();
    input();
    solve();
    // print();
  }

  return 0;
}