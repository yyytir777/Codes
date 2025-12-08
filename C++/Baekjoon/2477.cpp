// 2477 cpp
#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> cnt_map;
vector<pair<int, int>> inp;
vector<int> nums;
vector<int> length[5];

void input() {
  cin >> n;

  int a, b;
  for(int i = 0; i < 6; i++) {
    cin >> a >> b;
    inp.push_back({a,b});
    cnt_map[a]++;
    length[a].push_back(b);
    sort(length[a].begin(), length[a].end());
  }

  for(int i = 1; i < 5; i++) {
    if(length[i].size() == 2) {
      nums.push_back(i);
    }
  }
}

bool existed(int num) {
  for(int t : nums) {
    if(t == num) return true;
  }
  return false;
}

void solve() {
  vector<int> total_size;
  vector<int> sub_size;

  for(int i = 1; i < 5; i++) {
    if(cnt_map[i] == 1) total_size.push_back(length[i][0]);
    else sub_size.push_back(length[i][0]);
  }

  vector<int> temps;
  for(auto node : inp) {
    if(existed(node.first)) temps.push_back(node.second);
  }

  for(auto tmp : temps) {
    printf("%d ", tmp);
  }

  cout << n * (total_size[0] * total_size[1] - temps[1] * temps[2]);
}

int main() {
  input();
  solve();
  return 0;
}