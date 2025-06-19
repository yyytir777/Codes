// 1744 cpp
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n;
int arr[MAX];
int dp[MAX];

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> arr[i];
}

void solve() {
  sort(arr + 1, arr + n + 1);
  dp[0] = 0;
  dp[1] = arr[1];
  dp[2] = max(arr[1] + arr[2], arr[1] * arr[2]);


  /*
  
  1, 2, 3 =>
  1, (2, 3)
  (1, 2), 3
  1, 2, 3

  (-3, 0) 0 1 1 (2 3)
  */

  int result = arr[1];
  for(int i = 3; i <= n; i++) {
    dp[i] = max(dp[i-2] + arr[i] * arr[i-1], 
      max(dp[i-3] + arr[i-2] * arr[i-1] + arr[i], dp[i-1] + arr[i]));
  }

  cout << dp[n];
}

int main() {
  input();
  solve();
  return 0;
}