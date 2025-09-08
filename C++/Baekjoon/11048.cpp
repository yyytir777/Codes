// 11048 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, m;
int maze[MAX][MAX];
int dp[MAX][MAX] = {0,};

void input() {
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> maze[i][j];
    }
  }
}

int get_value(int r, int c) {
  if(r < 0 || r > n || c < 0 || c > m) return 0;
  return dp[r][c];
}

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << '\n';
  }
}

void init() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dp[i][j] = maze[i][j];
    }
  }
}

void solve() {
  init();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dp[i][j] += max(get_value(i-1, j-1), max(get_value(i, j-1), get_value(i-1, j)));
    }
  }

  cout << dp[n-1][m-1];
}

int main() {
  input();
  solve();
  return 0;
}