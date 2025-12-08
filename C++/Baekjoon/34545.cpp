// 34545 cpp
#include <bits/stdc++.h>
using namespace std;

/*

cur, target 비교
-> must be reset max -> toggle each
-> must be set max -> set_all

*/

int n, cnt = 0;
vector<bool> cur;
vector<bool> target;

void input() {
  cin >> n;
  bool flag;
  for(int i = 0; i < n; i++) {
    cur.push_back(flag);
  }

  for(int i = 0; i < n; i++) {
    target.push_back(flag);
  }
}

bool eqauls(vector<bool>& a, vector<bool>& b) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i]) return false;
  }
  return true;
}

void toggle(vector<bool>& a, int idx) {
  if(a[idx] == 0) a[idx] = 1;
  else a[idx] = 0;
}

void set_all(vector<bool>& a) {
  for(int i = 0; i < a.size(); i++) {
    a[i] = 1;
  }
}

bool check_set_all(vector<bool>& a) {
  for(int i = 0; i < a.size(); i++) {
    if(a[i] == 0) return false;
  }
  return true;
}

void reset_all(vector<bool> & a) {
  if(!check_set_all(a)) return;

  for(int i = 0; i < a.size(); i++) {
    a[i] = 0;
  }
}

void dfs(vector<bool>& node) {
  if(eqauls(node, target)) return;

  if(check_set_all(node)) {
    // all_uncheck();
    dfs();
    // rollback();
  } else {
    
  }
}

void solve() {
  dfs(cur);
}

int main() {
  input();
  solve();
  return 0;
}