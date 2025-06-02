// 16236 cpp
#include <bits/stdc++.h>
#define MAX 21
#define BLANK 0
#define SHARK 9
using namespace std;

typedef pair<int, int> Pair;

int n;
int space[MAX][MAX];
int shark_size = 2;
int take_cnt = 0;
int result = 0;
queue<Pair> q;
Pair shark_pos;
int visited[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};

// 위, 왼쪽 (priority)
int row_axis[4] = {-1, 0, 1, 0};
int col_axis[4] = {0, -1, 0, 1};


void input() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> space[i][j];
      if(space[i][j] == SHARK) {
        shark_pos = {i, j};
        space[i][j] = 0;
      }
    }
  }
}

void init() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      dist[i][j] = 0;
      visited[i][j] = 0;
    }
  }

  while(!q.empty()) q.pop();
}

bool compare(pair<Pair, int> a, pair<Pair, int> b) {
  if(a.second != b.second) return a.second < b.second;
  else {
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
    else return a.first.second < b.first.second;
  }
}

bool bfs() {
  init();
  vector<pair<Pair, int>> candidates;
  q.push(shark_pos);

  while (!q.empty()) {
    Pair cur_pos = q.front();
    visited[cur_pos.first][cur_pos.second] = 1;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_row = cur_pos.first + row_axis[i];
      int next_col = cur_pos.second + col_axis[i];

      if(next_row < 0 || next_row >= n || next_col < 0 || next_col >= n) continue;
      if(visited[next_row][next_col]) continue;
      if(shark_size < space[next_row][next_col]) continue;

      visited[next_row][next_col] = 1;
      dist[next_row][next_col] = dist[cur_pos.first][cur_pos.second] + 1;

      if(space[next_row][next_col] != 0 && space[next_row][next_col] < shark_size) {
        candidates.push_back({{next_row, next_col}, dist[next_row][next_col]});
      }

      q.push({next_row, next_col});
      
    }
  }

  if(candidates.empty()) return false;

  sort(candidates.begin(), candidates.end(), compare);
  pair<Pair, int> target = candidates[0];

  result += target.second;
  shark_pos = target.first;
  space[target.first.first][target.first.second] = BLANK;


  take_cnt++;
  if(take_cnt == shark_size) {
    shark_size++;
    take_cnt = 0;
  }

  return true;
}

void solve() {
  while(1) {
    if(!bfs()) break;
  }

  cout << result;
}

int main() {
  input();
  solve();
}
