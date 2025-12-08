// 34546 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> towers;

void input() {
  cin >> n;
  int tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    towers.push_back(tmp);
  }
}

void solve() {
  long long cost = 0;
  sort(towers.begin(),towers.end());

  int min_length = towers[0];

  for(auto tower : towers) {
    cost += tower - min_length;
  }

  cout << cost;
}

int main() {
  input();
  solve();
  return 0;
}
