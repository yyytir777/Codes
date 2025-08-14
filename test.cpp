// 13305 cpp
#include <bits/stdc++.h>
#define INF 2200000000
using namespace std;

typedef unsigned long long ll;

int n;
vector<ll> city;
vector<ll> cost;

void input() {
  cin >> n;

  int tmp;
  for(int i = 0; i < n - 1; i++) {
    cin >> tmp;
    city.push_back(tmp);
  }

  for(int i = 0; i < n; i++) {
    cin >> tmp;
    cost.push_back(tmp);
  }
}

void solve() {
  ll sum = 0;
  int city_idx = 0, min_idx = 0;
  while(city_idx < n - 1) {
    if(cost[min_idx] >= cost[city_idx]) {
      min_idx = city_idx;
    }
    ll city_sum = cost[min_idx] * city[city_idx];
    city_idx++;
    // cout << city_sum << "\n";
    sum += city_sum;
  }
  cout << sum;
}

int main() {
  input();
  solve();
  return 0;
}