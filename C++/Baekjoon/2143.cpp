// 2143 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef long long ll;

int t, n, m;
ll answer = 0;
int a[MAX], b[MAX];
map<int, ll> a_cnt;

void input() {
  cin >> t;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i+1];
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> b[i+1];
  }
}

void solve() {
  for(int i = 1; i <= n; i++) {
    ll sum = 0;
    for(int j = i; j <= n; j++) {
      sum += a[j];
      a_cnt[sum] += 1;
    }
  }

  for(int i = 1; i <= m; i++) {
    ll sum = 0;
    for(int j = i; j <= m; j++) {
      sum += b[j];
      answer += a_cnt[t - sum];
    }
  }

  cout << answer;
}

int main() {
  input();
  solve();
  return 0;
}
