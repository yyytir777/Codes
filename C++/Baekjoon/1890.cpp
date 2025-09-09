// 1890 cpp
#include <bits/stdc++.h>
#define MAX 101
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;

int n;
int board[MAX][MAX];
bool visited[MAX][MAX] = {0,};
ll dp[MAX][MAX] = {0,};

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
    }
  }
}

void solve() {
  dp[n-1][n-1] = 1;
  for(int i = n - 1; i >= 0; i--) {
    for(int j = n - 1; j >= 0; j--) {
      int dist = board[i][j];

      if(i == n - 1 && j == n - 1) continue;
      dp[i][j] = dp[i][j+dist] + dp[i+dist][j];
    }
  }

  cout << dp[0][0];
}

int main() {
  input();
  solve();
  return 0;
}