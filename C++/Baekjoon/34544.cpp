// 34544 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

void input() {
  cin >> n;
  int a, b;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a,b});
  }
}

void solve() {
  int result = 0;
  for(auto node : v) {
    if(node.first * node.second < 0) {
      if(node.second > node.first) {
        result += node.second - node.first - 1;
      }
      else if(node.first == node.second) continue;
      else {
        result += node.second - node.first + 1;
      }
    }
    else {
      result += node.second - node.first;
    }
  }

  if(1 + result <= 0) cout << 1 + result - 1;
  else cout << 1 + result;
}

int main() {
  input();
  solve();
  return 0;
}