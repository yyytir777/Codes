// 2011 cpp
#include <bits/stdc++.h>
#define MAX 5001
using namespace std;


/*
dp[0] = 1
dp[1] = 1
dp[2] = dp[1] + dp[0] = 2
do[3] = dp[1] = 2
dp[4] = dp[2] + dp[3] = 4
dp[5] = dp[3] + dp[4] = 6


25114
*/
string tmp;
int chars[MAX];
int dp[MAX];

void input() {
  cin >> tmp;

  for(int i = 0; i < tmp.size(); i++) {
    chars[i+1] = tmp[i] - '0';
  }
}

void solve() {
  if(chars[1] == 0) {
    cout << "0";
    return;
  }

  for(int i = 1; i <= tmp.size(); i++) {
    if(chars[i] < 0 || chars[i] > 26) {
      cout << "0";
      return;
    }
  }

  dp[0] = 1;
  for(int i = 1; i <= tmp.size(); i++) {
    if(chars[i] > 0 && chars[i] < 10)
      dp[i] = (dp[i-1] + dp[i]) % 1000000;

    if(i == 1) continue;

    if(chars[i-1] * 10 + chars[i] >= 10 && chars[i-1] * 10 + chars[i] <= 26)
      dp[i] = (dp[i-2] + dp[i]) % 1000000;
  }


  cout << dp[tmp.size()] << '\n';
}

void print() {
  for(int i = 1; i <= tmp.size(); i++) {
    cout << dp[i] << " ";
  }
}

int main() {
  input();
  solve();
  // print();
  return 0;
}