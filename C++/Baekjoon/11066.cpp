// 11066 cpp
#include <bits/stdc++.h>
#define MAX 501
#define INF 987654321
using namespace std;

int k;
vector<int> files;
int dp[MAX][MAX];
int sums[MAX];

void init() {
  files.clear();
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < k; j++) {
      dp[i][j] = 0;
    }
  }
}

void input() {
  cin >> k;
  int tmp;
  for(int i = 0; i < k; i++) {
    cin >> tmp;
    files.push_back(tmp);
    if(i == 0) sums[i] = tmp;
    else sums[i] = sums[i-1] + tmp;
  }
}

void solve() {
  init();
  for(int i = 0; i < k; i++) {
    dp[i][i] = 0;
  }

  int sum = 0;
  for(int l = 1; l < k; l++) {

    for(int i = 0; i + l < k; i++) {
      int j = i + l;
      dp[i][j] = INF;

      for(int idx = i; idx < j; idx++) {
        dp[i][j] = min(dp[i][j], dp[i][idx] + dp[idx+1][j] + sums[j] - sums[i-1]);
      }
    }
  }
  cout << dp[0][k-1] << '\n';
}

int tc;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> tc;
  for(int i = 0; i < tc; i++) {
    input();
    solve();
  }
  return 0;
}