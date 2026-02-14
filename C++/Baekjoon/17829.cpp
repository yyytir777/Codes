// 17829 cpp
#include <bits/stdc++.h>
#define MAX 1025
using namespace std;

typedef pair<int, int> Pair;
int n;
int matrix[MAX][MAX];


void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> matrix[i][j];
    }
  }
}
  
int getSecondMax(Pair node) {
  vector<int> sorted;

  int r = node.first;
  int c = node.second;
  sorted.push_back(matrix[r][c]);
  sorted.push_back(matrix[r][c+1]);
  sorted.push_back(matrix[r+1][c]);
  sorted.push_back(matrix[r+1][c+1]);

  sort(sorted.begin(), sorted.end());

  return sorted[sorted.size() - 2];
}

void divide(Pair s, int length) {
  if(length == 1) return;
  int r_mid = s.first + length / 2;
  int c_mid = s.second + length / 2;
  if(length > 3) {
    divide(s, length / 2);
    divide({s.first, c_mid}, length / 2);
    divide({r_mid, s.second}, length / 2);
    divide({r_mid, c_mid}, length / 2);
    return;
  }
  
  if(length == 2) {
    int i = s.first / 2 + 1;
    int j = s.second / 2 + 1;
    matrix[i][j] = getSecondMax(s);
  }
}

void solve() {
  int tmp = n;
  while(tmp >= 2) {
    divide({1,1}, tmp);
    tmp /= 2;
  }

  cout << matrix[1][1];
}

int main() {
  input();
  solve();
  return 0;
}