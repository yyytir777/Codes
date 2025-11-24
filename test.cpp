#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> files;
map<string, int> dicts;

void input() {
  cin >> n;
  string tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    files.push_back(tmp);
  }
}

void solve() {
  string ex;
  for(string file : files) {
    for(int i = 0; i < file.size(); i++) {
      if(file[i] == '.') {
        ex = file.substr(i + 1, file.size());
        dicts[ex] += 1;
      }
    }
  }

  for(auto dict : dicts) {
    cout << dict.first << " " << dict.second << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}