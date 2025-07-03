// 1937 cpp
#include <bits/stdc++.h>
#define MAX 501
using namespace std;

typedef pair<int, int> Pair;

int n;
int forest[MAX][MAX];
int dp[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int max_cnt = 0;

int r_axis[4] = {1, -1, 0, 0};
int c_axis[4] = {0, 0, 1, -1};

void input() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> forest[i][j];
    }
  }
}

int dfs(Pair s) {
  if(dp[s.first][s.second] != 0) return dp[s.first][s.second];
  
  dp[s.first][s.second] = 1;

  for(int i = 0; i < 4; i++) {
    int nx = s.first + r_axis[i];
    int ny = s.second + c_axis[i];

    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if(forest[s.first][s.second] >= forest[nx][ny]) continue;

    dp[s.first][s.second] = max(dp[s.first][s.second], dfs({nx,ny}) + 1);
  }

  return dp[s.first][s.second];
}

void solve() {
  int max_cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      max_cnt = max(max_cnt, dfs({i,j}));
    }
  }

  cout << max_cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
  return 0;
}