// 7785 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
set<string> s;

void input() {
  cin >> n;

  string str1, str2;
  for(int i = 0; i < n; i++) {
    cin >> str1 >> str2;

    if(str2 == "enter") {
      s.insert(str1);
    }
    else if(str2 == "leave") {
      s.erase(str1);
    }
  }
}

void solve() {
  for(auto iter = s.rbegin(); iter != s.rend(); ++iter) {
    cout << *iter << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}