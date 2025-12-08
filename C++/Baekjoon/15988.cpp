// 15988 cpp
#include <bits/stdc++.h>
#define MAX 1000001
#define REST 1000000009
using namespace std;

int t, n;
long long dp[MAX];

int main() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i = 4; i < MAX; i++) {
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % REST;
  }

  cin >> t;
  while(t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }  
}