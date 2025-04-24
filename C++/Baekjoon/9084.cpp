// 9084 cpp
#include <bits/stdc++.h>
#define P_MAX 21
#define M_MAX 10001
#define INF 987654321
using namespace std;

int tc;
int n, m;
int p[P_MAX], dp[M_MAX] = {0,};

void init() {
  for(int i = 0; i <= m; i++) {
    dp[i] = 0;
  }
}

void input() {
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> p[i];

  cin >> m;
}

void solve() {
  dp[0] = 1;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= m; j++) {
      if(j - p[i] < 0) continue;
      dp[j] += dp[j - p[i]];
    }
  }

  cout << dp[m] << '\n';
}

void print() {
  for(int i = 0; i <= m; i++) {
    cout << dp[i] << " ";
  }
}

int main() {
  cin >> tc;
  while(tc--) {
    input();
    init();
    solve(); 
    // print();
  }
  return 0;
}