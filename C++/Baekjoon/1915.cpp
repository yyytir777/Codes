// 1915 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, m;
int graph[MAX][MAX] = {0,};
int dp[MAX][MAX] = {0,};

void input() {
  cin >> n >> m;

  string tmp;
  for(int i = 1; i <= n; i++) {
    cin >> tmp;

    for(int j = 1; j <= m; j++) {
      graph[i][j] = tmp[j-1] - '0';
    }
  }
}

void init_dp() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(i == 1 || j == 1) dp[i][j] = graph[i][j];
    }
  }
}

int findMaxLength() {
  int maxLength = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      maxLength = max(maxLength, dp[i][j]);
    }
  }
  return maxLength;
}

void solve() {
  for(int i = 2; i <= n; i++) {
    for(int j = 2; j <= m; j++) {
      if(graph[i][j] == 1) dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
    }
  }

  int maxLength = findMaxLength();
  cout << maxLength * maxLength << '\n';
}

void print() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << '\n';
  }
}

int main() {
  input();
  init_dp();
  solve();
  // print();
  return 0;
}