// 2146 cpp
#include <bits/stdc++.h>
#define MAX 101
#define INF 987654321
using namespace std;

typedef pair<int, int> Pair;

int n;
int min_dist = INF;
int graph[MAX][MAX];
int visited[MAX][MAX] = {0,};
queue<pair<Pair, int>> q;
int color_code = 2;

int r_axis[4] = {0, 0, 1, -1};
int c_axis[4] = {1, -1, 0, 0};

void input() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }
}

void init_dist() {
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      visited[i][j] = 0;
    }
  }
}

bool isQualified(Pair a) {
  if(graph[a.first][a.second] == 0) return false;
  int r, c;
  for(int i = 0; i < 4; i++) {
    r = a.first + r_axis[i];
    c = a.second + c_axis[i];

    if(r < 0 || r >= n || c < 0 || c >= n) continue;
    if(graph[r][c] == 0) return true;
  }
  return false;
}

bool isEnd(Pair node, int color) {
  int r, c;
  for(int i = 0; i < 4; i++) {
    r = node.first + r_axis[i];
    c = node.second + c_axis[i];

    if(r < 0 || r >= n || c < 0 || c >= n) continue;
    if(graph[r][c] == color) continue;
    if(graph[r][c] != 0) return true;
  }
  return false;

}

void bfs(Pair  start) {
  int cur_color = graph[start.first][start.second];
  q.push({start, 0});
  visited[start.first][start.second] = 1;

  while(!q.empty()) {
    Pair cur = q.front().first;
    int bridge = q.front().second;
    q.pop();

    // printf("(%d, %d)\n", cur.first, cur.second);

    for(int i = 0; i < 4; i++) {
      int nr = cur.first + r_axis[i];
      int nc = cur.second + c_axis[i];

      if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if(visited[nr][nc]) continue;
      if(isEnd({nr, nc}, cur_color)) {
        min_dist = min(min_dist, bridge + 1);
        return;
      }

      q.push({{nr, nc}, bridge+1});
      visited[nr][nc] = 1;
    }
  }
}

void colored(Pair start) {
  queue<Pair> q;
  q.push(start);
  visited[start.first][start.second] = 1;
  graph[start.first][start.second] = color_code;

  while(!q.empty()) {
    Pair cur = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nr = cur.first + r_axis[i];
      int nc = cur.second + c_axis[i];

      if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if(graph[nr][nc] == 1 && !visited[nr][nc]) {
        visited[nr][nc] = 1;
        graph[nr][nc] = color_code;
        q.push({nr,nc});
      }
    }
  }
}

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}

void init_queue() {
  while(!q.empty()) {
    q.pop();
  }
}

void solve() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(graph[i][j] == 1) {
        init_dist();
        colored({i, j});
        color_code += 1;
      }

      if(isQualified({i,j})) {
        init_dist();
        init_queue();
        // printf("begin bfs(%d, %d)\n", i, j);
        bfs({i,j});
      }
    }
  }

  cout << min_dist;
}

int main() {
  input();
  solve();
  return 0;
}