// 11652 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
map<long long, int> m;

void input() {
  cin >> n;
  long long tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    m[tmp]++;
  }
}

void solve() {
  int max_cnt = 0;
  long long max_idx;
  for(auto node : m) {
    if(max_cnt < node.second) {
      max_cnt = node.second;
      max_idx = node.first;
    }
    else if(max_cnt == node.second && max_idx > node.first) {
      max_idx = node.first;
    }
  }

  cout << max_idx;
}

void print() {
  for(auto node : m) {
    printf("%lld : %d times\n", node.first, node.second);
  }
}

int main() {
  input();
  solve();
  // print();
  return 0;
}