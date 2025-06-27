// 11054 cpp
#include <bits/stdc++.h>
#include <cstdarg>
#define MAX 1001
using namespace std;

int n;
int arr[MAX], dp1[MAX], dp2[MAX];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

}

void init_dp() {
  for(int i = 0; i < n; i++) {
    dp1[i] = 1;  
    dp2[i] = 1;
  }
}

void increase_dp() {
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(arr[j] < arr[i]){
        dp1[i] = max(dp1[i], dp1[j] + 1);
      }
    }
  }
}

void decrease_dp() {
  for(int i = n - 2; i >= 0; i--) {
    for(int j = n - 1; j > i; j--) {
      if(arr[j] < arr[i]) {
        dp2[i] = max(dp2[i], dp2[j] + 1);
      }
    }
  }
}

void solve() {
  init_dp();
  increase_dp();
  decrease_dp();

  // for(int i = 0; i < n; i++) {
  //   cout << dp1[i] << " ";
  // }

  // cout << "\n\n";

  // for(int i = 0; i < n; i++) {
  //   cout << dp2[i] << " ";
  // }

  int max_result = 0;
  for(int i = 0; i < n; i++) {
    max_result = max(max_result, dp1[i] + dp2[i]);
    // printf("idx : %d => %d / %d\n", i, dp1[i], dp2[i]);
  }

  cout << max_result - 1;
}

int main() {
  input();
  solve();
  return 0;
}