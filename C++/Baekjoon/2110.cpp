// 2110 cpp
#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> houses;

void input() {
  cin >> n >> c;

  int tmp;
  for(int i = 0; i < n; i++) {
    cin >>tmp;
    houses.push_back(tmp);
  }

  sort(houses.begin(), houses.end());
}

void solve() {
  int min_dist = 1;
  int max_dist = houses[n-1] - houses[0];
  int result = 0;

  while(min_dist <= max_dist) {
    int start_router = houses[0];
    int mid_dist = (min_dist + max_dist) / 2;

    int router_cnt = 1;
    for(int i = 1; i < n; i++) {
      if(houses[i] - start_router >= mid_dist) {
        router_cnt++;
        start_router = houses[i];
      }
    }

    if(router_cnt < c) {
      max_dist = mid_dist - 1;
    }
    else {
      result = mid_dist;
      min_dist = mid_dist + 1;
    }
  }

  cout << result;
}

int main() {
  input();
  solve();
  return 0;
}