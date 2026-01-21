// 2631 cpp
#include <bits/stdc++.h>
#define MAX 203
using namespace std;

int n;
int line[MAX];
// i번째 위치까지에서, 가장 긴 증가하는 수열 -> dp[i]
int dp[MAX] = {1,};

void input() {
  cin >> n;

  for(int i = 1 ; i <= n; i++) {
    cin >> line[i];
  }
}

void solve() {

  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
  }

  int tmp = 0;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      
      if(line[i] > line[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }

  int max_cnt = 0;
  for(int i = 1; i <= n; i++) {
    max_cnt = max(max_cnt, dp[i]);
  }

  cout << n - max_cnt;
}

int main() {
  input();
  solve();
  return 0;
}