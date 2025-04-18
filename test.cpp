// 9934 cpp
#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

// LVR
int k, n = 1;
int seq[MAX];
vector<int> tree[10];

void input() {
  cin >> k;

  int cnt = 0;
  while(cnt < k) {
    n *= 2;
    cnt++;
  }

  for(int i = 0; i < n; i++) {
    cin >> seq[i+1];
  }
}

int cnt = 1;
void dfs(int d, int s, int e) {
  if(s >= e) return;
  int mid = (s + e) / 2;


  dfs(d + 1, s, mid);
  tree[d].push_back(seq[mid]);
  dfs(d + 1, mid + 1, e);
}

void solve() {
  dfs(0, 1, n);
}

void output() {
  for(int i = 0; i < k; i++) {
    for(int node : tree[i]) {
      cout << node << " ";
    }
    cout << '\n';
  }
}

void print() {
  for(int i = 1; i < n; i++) {
    cout << seq[i] << " ";
  }
}

int main() {
  input();
  solve();
  output();
  return 0;
}