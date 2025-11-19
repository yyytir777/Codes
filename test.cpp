// 1080 cpp
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n, m;
int a[MAX][MAX];
int b[MAX][MAX];

void input() {
  cin >> n >> m;
  
  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < m; j++) {
        a[i][j] = tmp[j] - '0';
    }
  }

  for(int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < m; j++) {
      b[i][j] = tmp[j] - '0';
    }
  }
}

void swap(int idx1, int idx2) {
  for(int i = idx1; i < idx1 + 3; i++) {
    for(int j = idx2; j < idx2 + 3; j++) {
      a[i][j] = a[i][j] == 0 ? 1 : 0;
    }
  }
}

void print_a() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }
}

void print_b() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << b[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() {
  if(n < 3 || m < 3) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(a[i][j] != b[i][j]) {
          cout << "-1";
          return;
        }
      }
    }
    cout << "0";
    return;
  }

  int answer = 0;
  for(int i = 0; i < n - 2; i++) {
    for(int j = 0; j < m - 2; j++) {
      if(a[i][j] != b[i][j]) {
        swap(i, j);
        answer++;
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] != b[i][j]) {
        cout << "-1";
        return;
      }
    }
  }
  cout << answer;
}

int main() {
  input();
  solve();
  return 0;
}