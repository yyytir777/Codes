// 3055 cpp
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

typedef pair<int, int> Pair;

int r, c;
int result = 0;
char forest[MAX][MAX];
int dist[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
vector<Pair> floods;
Pair s, d;
queue<pair<Pair, int>> q;

int raxis[4] = {1, -1, 0, 0};
int caxis[4] = {0, 0, 1, -1};

void input() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> forest[i][j];

      if(forest[i][j] == 'S') s = {i,j};
      if(forest[i][j] == 'D') d = {i,j};
    }
  }
}

void flooding() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(forest[i][j] == '*') floods.push_back({i,j});
    }
  }

  for(auto flood : floods) {
    for(int i = 0; i < 4; i++) {
      int nr = flood.first + raxis[i];
      int nc = flood.second + caxis[i];

      if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
      if(forest[nr][nc] == 'X') continue;
      if(forest[nr][nc] == 'D' || forest[nr][nc] == 'S') continue;
      forest[nr][nc] = '*';
    }
  }

  while(!floods.empty()) {
    floods.pop_back();
  }
}

void print() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << forest[i][j] << " ";
    }
    cout << "\n";
  }
  cout << '\n';
}

void bfs() {
  int depth = 0;
  q.push({{s.first, s.second}, 1});
  visited[s.first][s.second] = 1;

  while(!q.empty()) {
    auto cur_node = q.front();
    Pair cur_pos = cur_node.first;
    q.pop();

    if(forest[cur_pos.first][cur_pos.second] == 'D') {
      result = dist[cur_pos.first][cur_pos.second];
      break;
    }


    if(cur_node.second > depth) {
      flooding();
      depth = cur_node.second;
    }

    for(int i = 0; i < 4; i++) {
      int nr = cur_pos.first + raxis[i];
      int nc = cur_pos.second + caxis[i];

      if(visited[nr][nc]) continue;
      if(forest[nr][nc] == '*') continue;
      else if(forest[nr][nc] == '.' || forest[nr][nc] == 'D') {
        dist[nr][nc] = dist[cur_pos.first][cur_pos.second] + 1;
        visited[nr][nc] = 1;
        q.push({{nr, nc}, cur_node.second + 1});
      }
    }
  }
}

void solve() {
  bfs();
  if(result == 0) cout << "KAKTUS";
  else cout << result;
}

int main() {
  input();
  solve();
  return 0;
}