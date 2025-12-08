// 1600 cpp
#include <bits/stdc++.h>
#define INF 987654321
#define MAX 201
#define BLANK 0
#define WALL 1
using namespace std;

typedef pair<int,int> Pair;

int k, w, h;
int graph[MAX][MAX];
// [말 이동 횟수][row][col]; -> 키포인트
bool visited[30][MAX][MAX] = {0,};
int cnts_min = INF;

int x_axis[4] = {1, -1, 0, 0};
int y_axis[4] = {0, 0, -1, 1};

int x_horse[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int y_horse[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void input() {
  cin >> k;
  cin >> w >> h;

  int tmp;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> graph[i][j];
    }
  }
}

void bfs(Pair start) {
  queue<pair<Pair, Pair>> q;
  q.push({start, {0, 0}});
  visited[0][start.first][start.second] = 1;


  while(!q.empty()) {
    Pair node = q.front().first;
    Pair info = q.front().second;
    // printf("(%d, %d)\n", node.first, node.second);
    q.pop();

    if(node.first == h-1 && node.second == w-1) {
      cnts_min = min(cnts_min, info.second);
      return;
    }

    for(int i = 0; i < 4; i++) {
      int nxt_x = node.first + x_axis[i];
      int nxt_y = node.second + y_axis[i];

      if(nxt_x >= h || nxt_y >= w || nxt_x < 0 || nxt_y < 0) continue;
      if(visited[info.first][nxt_x][nxt_y] || graph[nxt_x][nxt_y] == WALL) continue;

      visited[info.first][nxt_x][nxt_y] = 1;
      q.push({{nxt_x, nxt_y}, {info.first, info.second + 1}});
    }

    if(info.first < k) {
      for(int i = 0; i < 8; i++) {
        int nxt_x = node.first + x_horse[i];
        int nxt_y = node.second + y_horse[i];

        if(nxt_x >= h || nxt_y >= w || nxt_x < 0 || nxt_y < 0) continue;
        if(visited[info.first + 1][nxt_x][nxt_y] || graph[nxt_x][nxt_y] == WALL) continue;

        visited[info.first + 1][nxt_x][nxt_y] = 1;
        q.push({{nxt_x, nxt_y}, {info.first + 1, info.second + 1}});
      }
    }
  }
}

void solve() {
  bfs({0,0});

  if(cnts_min != INF) {
    cout << cnts_min;
  } else {
    cout << "-1";
  }
}

int main() {
  input();
  solve();
  return 0;
}