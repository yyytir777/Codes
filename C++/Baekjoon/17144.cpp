// 17144 cpp
#include <iostream>
#include <vector>
#define MAX 51
using namespace std;

int r, c, t;
int room[MAX][MAX];
int tmp[MAX][MAX] ={0,};
vector<pair<int, int>> air_fresh;

int row_axis[4] = {0, 0, 1, -1};
int col_axis[4] = {1, -1, 0, 0};

void init_tmp() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      tmp[i][j] = 0;
    }
  }
}

void print() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << room[i][j] << " ";
    }
    cout << '\n';
  }
}

void difuse() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(room[i][j] == 0 || room[i][j] == -1) continue;

      int cnt = 0;
      for(int k = 0; k < 4; k++) {
        int tmp_row = i + row_axis[k]; 
        int tmp_col = j + col_axis[k];

        if(0 > tmp_row || 0 > tmp_col || r <= tmp_row || c <= tmp_col) continue;
        if(room[tmp_row][tmp_col] == -1) continue;

        tmp[tmp_row][tmp_col] += room[i][j] / 5;
        cnt++;
      }
      tmp[i][j] += (room[i][j] - cnt * (room[i][j] / 5));
    }
  }

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(room[i][j] == -1) continue;
      room[i][j] = tmp[i][j];
    }
  }
}

void cycle() {
  // 반시계 방향
  pair<int, int> node = air_fresh[0];
  int row = node.first;
  int col = node.second;
  while(true) {
    if(row == 0) break;
    if(room[row][col] == -1) {
      row--;
      continue;
    }
    room[row][col] = room[row - 1][col];
    row--;
  }

  while(true) {
    if(col == c - 1) break;
    room[row][col] = room[row][col + 1];
    col++;
  }

  while(true) {
    if(row == node.first) {
      break;
    }
    room[row][col] = room[row + 1][col];
    row++;
  }

  while(true) {
    if(col == node.second + 1) {
      room[row][col] = 0;
      break;
    }
    room[row][col] = room[row][col - 1];
    col--;
  }
  
  // 시계 방향
  node = air_fresh[1];
  row = node.first;
  col = node.second;
  while(true) {
    if(row == r - 1) break;
    if(room[row][col] == -1) {
      row++;
      continue;
    }
    room[row][col] = room[row + 1][col];
    row++;
  }

  while(true) {
    if(col == c - 1) break;
    room[row][col] = room[row][col + 1];
    col++;
  }

  while(true) {
    if(row == node.first) break;
    room[row][col] = room[row - 1][col];
    row--;
  }

  while(true) {
    if(col == node.second + 1) {
      room[row][col] = 0;
      break;
    }
    room[row][col] = room[row][col - 1];
    col--;
  }
}

void input(){
  cin >> r >> c >> t;

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> room[i][j];
      if(room[i][j] == -1) air_fresh.push_back({i, j});
    }
  }
}

void solve() {
  while(t--) {
    init_tmp();
    difuse();
    cycle();
    // print();
  } 
}

int count_pollution() {
  int cnt = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(room[i][j] != -1) cnt += room[i][j];
    }
  }
  return cnt;
}

int main() {
  input();
  solve();
  cout << count_pollution();
  return 0;
}
