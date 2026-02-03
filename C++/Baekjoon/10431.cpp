// 10431 cpp
#include <bits/stdc++.h>
using namespace std;

int p, t;
vector<int> lines;

void solve() {
  int a, t;
  cin >> t;

  lines.clear();

  int cnt = 0;
  for(int i = 0; i < 20; i++) {
    cin >> a;

    for(int node : lines) {
      if(a < node) cnt++;
    }

    lines.push_back(a);
  }

  cout << t << " " << cnt << '\n';
}

int main() {
  cin >> p;
  while(p--) {
    solve();
  }
  return 0;
}