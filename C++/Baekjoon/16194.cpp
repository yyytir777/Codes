// 16194 cpp
#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1001
using namespace std;

int n;
// i개를 사기 위해 지불할 수 있는 금액의 최솟값
// dp[1] = p1;
// dp[2] = min(dp[1] + p1, p2)
// dp[3] = dp[3], dp[2] + dp[1]
// dp[4] = dp[4], dp[3] + dp[1], dp[2] + dp[2]
// ...
// dp[n] = min(dp[n-i] + pi) (0 <= i <= p)
int dp[MAX] = {0,};
vector<int> packs(MAX);

void input() {
  cin >> n;
  packs[0] = 0;
  for(int i = 1; i <= n; i++) {
    cin >> packs[i];
  }
}

void solve() {
  dp[0] = 0;
  dp[1] = packs[1];

  for(int i = 2; i <= n; i++) {

    int min_cost = packs[i];
    for(int j = 1; j <= i/2; j++) {
      min_cost = min(min_cost, dp[j] + dp[i-j]);
    }
    dp[i] = min_cost;

  }

  cout << dp[n];
}

int main() {
  input();
  solve();
  return 0;
}