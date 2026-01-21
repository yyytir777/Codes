// 5557 cpp
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

typedef long long ll;

int n;
// dp[i][N] => i번째 자리까지의 합의 N인 경우의 수
ll dp[MAX][21] = {0,};
int nums[MAX];


void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> nums[i+1];
  }
}

void solve() {
  dp[1][nums[1]] = 1;

  for(int i = 2; i < n; i++) {
    for(int j = 0; j <= 20; j++) {
      if(dp[i-1][j] == 0) continue;

      // 합이 [0, 20] 일 때
      int sum = j + nums[i];
      if(0 <= sum && sum <= 20) {
        dp[i][sum] += dp[i-1][j];
      }

      // 차가 [0, 20] 일 때
      int sub = j - nums[i];
      if(0 <= sub && sub <= 20) {
        dp[i][sub] += dp[i-1][j];
      }
    }
  }

  cout << dp[n-1][nums[n]];
}

void print() {
  for(int i = 1; i <= n; i++) {
    cout << nums[i] << " ";
  }
}

int main() {
  input();
  // print();
  solve();
  return 0;
}