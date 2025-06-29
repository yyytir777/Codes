// 2133 cpp
#include <bits/stdc++.h>
#define MAX 32
using namespace std;

typedef long long ll;

int n;
ll dp[MAX] = {0,};


void solve() {
  cin >> n;
  dp[2] = 3;

  for(int i = 4; i <= n; i += 2) {
    dp[i] += dp[i-2] * 3 + 2;
    for(int j = 4; j < i; j += 2) {
      dp[i] += 2 * dp[i-j];
    }
  }

  cout << dp[n];
}

int main() {
  solve();
  return 0;
}