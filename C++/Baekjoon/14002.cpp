// 14002 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n;
int nums[MAX];
int parent[MAX];
int dp[MAX] = {0,};

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> nums[i];
  }
}

void solve() {
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 1; j < i; j++) {
      if(nums[i] > nums[j]) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }

  int max_num = 0;
  for(int i = 1; i <= n; i++) {
    max_num = max(max_num, dp[i]);
  }

  cout << max_num << "\n";


  vector<int> results;
  for(int i = n; i > 0; i--) {
    if(dp[i] == max_num) {
      results.push_back(nums[i]);
      max_num--;
    }
  }

  sort(results.begin(), results.end());


  for(auto node : results) {
    cout << node << " ";
  }
}

int main() {
  input();
  solve();
  return 0;
}