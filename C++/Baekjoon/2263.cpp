// 2263 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
int inOrder[MAX];
int inOrderIdx[MAX];
int postOrder[MAX];

void input() {
  cin >> n;

  int tmp;
  for(int i = 1; i <= n; i++) {
    cin >> inOrder[i];
    inOrderIdx[inOrder[i]] = i;
  }

  for(int i = 1; i <= n; i++) {
    cin >> postOrder[i];
  }
}

void parsing(int s, int e, int subTreeS, int subTreeE) {
  if(e < s || subTreeE < subTreeS) return;

  int m = inOrderIdx[postOrder[subTreeE]];
  cout << postOrder[subTreeE] << " ";

  parsing(s, m - 1, subTreeS, subTreeS + m - s - 1);
  parsing(m + 1, e, subTreeS + m - s, subTreeE - 1);
}

void solve() {
  int s = 1, e = n;
  parsing(s, e, s, e);
}

int main() {
  input();
  solve();
  return 0;
}