// 4779 cpp
#include <bits/stdc++.h>
using namespace std;

int n;

int get_count() {
  int res = 1;
  for(int i = 0; i < n; i++) {
    res *= 3;
  }
  return res;
}

void recursive(int s, int e, bool colored) {
  // printf("recursive(%d, %d)\n", s, e);
  if(s == e) {
    if(colored) cout << "-";
    else cout << " ";
    return;
  }

  int diff = (e - s + 1) / 3;
  recursive(s, s + diff - 1, colored ? true : false);
  recursive(s + diff, s + 2 * diff - 1, false);
  recursive(e - diff + 1, e, colored ? true : false);
}

void solve() {
  int total = get_count();

  recursive(1, total, true);
  cout << "\n";
}

int main() {
  while(cin >> n) solve();
  return 0;
}