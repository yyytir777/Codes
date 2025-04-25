// 1965 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int box[MAX], dp[MAX];

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> box[i];
  }
}

void solve() {
  dp[1] = 1;

  for(int i = 2; i <= n; i++) {
    int max_dp = 1;
    for(int j = 1; j < i; j++) {
      if(box[i] > box[j]) max_dp = max(max_dp, dp[j] + 1);
    }
    dp[i] = max_dp;
  }

  sort(dp+1, dp+n+1);
  cout << dp[n];
}

void print() {
  for(int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
};

int main() {
  input();
  solve();
  // print();
  return 0;
}