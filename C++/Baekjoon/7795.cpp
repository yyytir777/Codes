// 7795 cpp
#include <algorithm>
#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int n, m;
int a[MAX], b[MAX];

void input() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
}

int binary_search(int num) {
  int start = 0, end = m, mid, result = 0;

  while(start + 1 < end) {
    mid = (start + end) / 2;

    if(num <= b[mid]) {
      end = mid;
    }
    else start = mid;
  }
  result += start;
  if(num > b[start]) result++;
  return result;
}

void solve() {
  sort(b, b+m);

  int sum = 0;
  for(int i = 0; i < n; i++) {
    int idx = binary_search(a[i]);
    // cout << idx << '\n';
    sum += idx;
  }
  cout << sum << "\n";
}

int main() {
  int tc; cin >> tc;
  while(tc--) {
    input();
    solve();
  }

  return 0;
}