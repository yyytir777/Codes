// 15486 cpp
#include <bits/stdc++.h>
#define MAX 1500001
using namespace std;

int n;
int t[MAX], p[MAX];
int dp[MAX] = {0,};

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> t[i] >> p[i];
  }
}

void solve() {
  dp[n] = (t[n] == 1) ? p[n] : 0;
  for(int i = n - 1; i >= 1; i--) {
    if(i + t[i] - 1 > n) dp[i] = dp[i+1];
    else dp[i] = max(dp[i+1], dp[i + t[i]] + p[i]);
  }

  cout << dp[1] << '\n';
}

void print() {
  for(int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << '\n';
}

int main() {
  input();
  solve();
  // print();
  return 0;
}