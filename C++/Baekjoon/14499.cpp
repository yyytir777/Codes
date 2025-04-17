// 14499 cpp
#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int n, m, x, y, k;
int graph[MAX][MAX];
int dice[7] = {0,};
vector<int> insts;

int row_axis[5] = {0, 0, 0, -1, 1};
int col_axis[5] = {0, 1, -1, 0, 0};

void swap(int i, int j) {
  int tmp = dice[i];
  dice[i] = dice[j];
  dice[j] = tmp;
  return;
}

int getTop() {
  return dice[1];
}

void move(int d) {
  if(d == 1) {
    swap(3, 1);
    swap(1, 4);
    swap(4, 6);
  }
  else if(d == 2) {
    swap(6, 4);
    swap(4, 1);
    swap(1, 3);
  }
  else if(d == 3) {
    swap(2, 1);
    swap(1, 5);
    swap(5, 6);
  }
  else {
    swap(6, 5);
    swap(5, 1);
    swap(1, 2);
  }
}

void input() {
  cin >> n >> m >> x >> y >> k;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> graph[i][j];
    }
  }

  int tmp;
  for(int i = 0; i < k; i++) {
    cin >> tmp;
    insts.push_back(tmp);
  }
}

void solve() {
  pair<int, int> cur_pos = {x, y};
  for(int i = 0; i < k; i++) {
    int d = insts[i];
    int tmp_row = cur_pos.first + row_axis[d];
    int tmp_col = cur_pos.second + col_axis[d];

    if(tmp_row < 0 || tmp_row >= n || tmp_col < 0 || tmp_col >= m) continue;

    cur_pos = {tmp_row, tmp_col};
    move(d);

    if(graph[tmp_row][tmp_col] == 0) {
       graph[tmp_row][tmp_col] = dice[6];
    }
    else {
      dice[6] = graph[tmp_row][tmp_col];
      graph[tmp_row][tmp_col] = 0;
    }

    cout << getTop() << '\n';
  }
}

int main() {
  input();
  solve();
  return 0;
}