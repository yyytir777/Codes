// 5582 cpp
#include <bits/stdc++.h>
#define MAX 4002
using namespace std;

/*
dp[i][j] = (i,j)에서 가장 긴 공통 부분 문자열의 길이
dp[0][0] = (str1[0] == str2[0]) ? 1 : 0

if(str1[i] == str2[j]) {
  dp[i][j] = dp[i-1][j-1] + 1;
}
else dp[i][j] = 0;

*/
char str1[MAX], str2[MAX];
int dp[MAX][MAX] = {0,};
int n, m;

void input() {
  string tmp1, tmp2;
  cin >> tmp1 >> tmp2;
  n = tmp1.size(), m = tmp2.size();

  for(int i = 0; i < n; i++) {
    str1[i] = tmp1[i];
  }

  for(int i = 0; i < m; i++) {
    str2[i] = tmp2[i];
  }
}

int getMax() {
  int res = 0;
  for(int i = 0; i < n; i++) {
    res = max(res, dp[i][m-1]);
  }
  return res;
}

void solve() {
  dp[0][0] = (str1[0] == str2[0]) ? 1 : 0;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(str1[i] == str2[j]) {
        if(i == 0 || j == 0) dp[i][j] = 1;
        else dp[i][j] = dp[i-1][j-1] + 1;
      }
    }
  }
}

void print() {
  int max_str = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      // cout << dp[i][j] << " ";
      max_str = max(max_str, dp[i][j]);
    }
    // cout << '\n';
  }
  cout << max_str;
}

int main() {
  input();
  solve();
  print();
  return 0;
}