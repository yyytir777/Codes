// 2812 cpp
#include <bits/stdc++.h>
#define MAX 500001
using namespace std;

int n, k, num[MAX];
vector<int> nums;

void input() {
  cin >> n >> k;

  string digits;
  cin >> digits;

  for(int i = 0; i < digits.length(); i++) {
    num[i] = digits[i] -'0';
  }
}

void solve() {
  int idx = 0, cnt = 0;

  for(int i = 0; i < n; i++) {
    while(!nums.empty() && nums.back() < num[i] && cnt < k) {
      nums.pop_back();
      cnt++;    
    }
    nums.push_back(num[i]);
  }

  while(cnt < k) {
    cnt++;
    nums.pop_back();
  }

  for(auto node :  nums) {
    cout << node;
  }
}

int main() {
  input();
  solve();
  return 0;
}