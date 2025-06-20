// 6603 cpp
#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int k;
vector<int> v;
vector<int> p;
bool visited[MAX] = {0,};

void print_queue() {
  for(auto node : p) {
    cout << node << " ";
  }
  cout << '\n';
}

void dfs(int depth, int idx) {
  if(idx > k) return;
  if(depth == 6) {
    print_queue();
    return;
  }

  p.push_back(v[idx]);
  visited[v[idx]] = 1;


  dfs(depth + 1, idx + 1);

  p.pop_back();
  visited[v[idx]] = 0;

  dfs(depth, idx + 1);
}

void solve() {
  dfs(0, 0);
}

void init() {
  v.clear();
  p.clear();

  for(int i = 0; i < k; i++) visited[i] = 0;
}

int main() {
  while(true) {
    cin >> k;
    if(k == 0) return 0;
    int tmp;
    for(int i = 0; i < k; i++) {
      cin >> tmp;
      v.push_back(tmp);
    }
    solve();
    init();
    cout << '\n';
  }
  return 0;
}