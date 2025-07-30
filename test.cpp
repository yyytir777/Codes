// 2776 cpp
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int t, n, m, answer = 0;
int note1[MAX], note2[MAX];

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> note1[i];
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> note2[i];
  }
}

bool binary_search(int num) {
  int start = 0, end = n - 1;

  while(start <= end) {
    int mid = (start + end) / 2;

    if(note1[mid] == num) return true;

    if(note1[mid] > num) end = mid - 1;
    else start = mid + 1;
  }

  return false;
}

void solve() {
  sort(note1, note1 + n);
  
  for(int i = 0; i < m; i++) {
    int num = note2[i];

    bool isExisted = binary_search(num);
    cout << isExisted << '\n';
  }
}

int main() {
  cin >> t;
  while(t--) {
    input();
    solve();  
  }
  return 0;
}