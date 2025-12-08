// 12919 cpp
#include <bits/stdc++.h>
using namespace std;

string s, t;

string reverse(string str) {
  string tmp = "";
  for(int i = str.length() - 1; i >= 0; i--) {
    tmp += str[i];
  }
  return tmp;
}

bool equal(string a, string b) {
  if(a.length() == b.length()) {
    for(int i = 0; i < a.length(); i++) {
      if(a[i] != b[i]) return false;
    }
    return true;
  }
  return false;
}

bool flag = 0;

void dfs() {
  // cout << "dfs was invoked : " << s << " : " << t << '\n';
  if(t.size() < s.size()) return;

  if(equal(s,t)) {
    flag = 1;
    return;
  }

  if(t.back() == 'A') {
    t.pop_back();
    dfs();
    t.push_back('A');
  }

  if(t.front() == 'B') {
    reverse(t.begin(), t.end());
    t.pop_back();

    dfs();

    t.push_back('B');
    reverse(t.begin(), t.end());
  }
}

void solve() {
  dfs();
  if(flag) cout << "1";
  else cout << "0";
}

int main() {
  cin >> s; cin >> t;
  solve();
  return 0;
}