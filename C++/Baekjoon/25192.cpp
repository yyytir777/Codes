// 25192 cpp
#include <bits/stdc++.h>
using namespace std;

int n, result = 0;
map<string, int> cnt;

void solve() {

  string tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    if(tmp == "ENTER") {
      cnt.clear();
      continue;
    }

    // 없다면, 추가
    if(cnt.find(tmp) == cnt.end()) {
      result++;
      cnt[tmp] = 1;
    }
    else continue;
  }
}

int main() {
  cin >> n;
  solve();
  cout << result;
  return 0;
}