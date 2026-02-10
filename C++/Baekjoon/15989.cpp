// 15989 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int t;  
int dp[MAX][4] = {0,};

void init() {
  dp[1][1] = 1;

  dp[2][1] = 1;
  dp[2][2] = 1;

  dp[3][1] = 1;
  dp[3][2] = 1;
  dp[3][3] = 1;

  for(int i = 4; i <= MAX; i++) {
    dp[i][1] = dp[i-1][1];
    dp[i][2] = dp[i-2][1] + dp[i-2][2];
    dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
  }
}

void solve() {
  int n;
  cin >> n;
  cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
}

int main() {
  init();
  cin >> t;
  while(t--) {
    solve();
  }  
  return 0;
}