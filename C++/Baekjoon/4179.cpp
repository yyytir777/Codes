// 4179 cpp
#include <bits/stdc++.h>
#define INF 987654321
#define MAX 1001
#define WALL '#'
#define BLANK '.'
#define START 'J'
#define FIRE 'F'
#define TEMP 'T'
using namespace std;

typedef pair<int, int> Pair;

int r, c;
char graph[MAX][MAX];
int r_axis[4] = {0, 0, 1, -1};
int c_axis[4] = {1, -1, 0, 0};
int dist[MAX][MAX] = {0,};
int f_dist[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
int min_time = INF;
Pair start;
queue<Pair> fires;


void print() {
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << graph[i][j] << " ";
    }
    cout << '\n';
  }
  cout << '\n';
}

void input() {
  cin >> r >> c;

  string tmp;
  for(int i = 0; i < r; i++) {
    cin >> tmp;
    for(int j = 0; j < c; j++) {
      graph[i][j] = tmp[j];
      if(graph[i][j] == START) {
        graph[i][j] = BLANK;
        start = {i,j};
      }
      else if(graph[i][j] == FIRE) fires.push({i,j});
    }
  }
}

bool isExit(Pair node) {
  if(graph[node.first][node.second] == BLANK && (node.first == 0 || node.first == r - 1)) return true;
  if(graph[node.first][node.second] == BLANK && (node.second == 0 || node.second == c - 1)) return true;
  return false;
}

void bfs(Pair start) {
  queue<pair<Pair, int>> q;

  while(!fires.empty()) {
    Pair fire = fires.front();

    for(int i = 0; i < 4; i++) {
      int nx = fire.first + r_axis[i];
      int ny = fire.second + c_axis[i];

      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

      if()
    }
  }


  visited[start.first][start.second] = 1;
  q.push({start, 1});

  while(!q.empty()) {
    pair<Pair, int> data = q.front();
    Pair node = data.first;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nxt_r = node.first + r_axis[i];
      int nxt_c = node.second + c_axis[i];
      
      if(nxt_r < 0 || nxt_r >= r || nxt_c < 0 || nxt_c >= c) continue;
      if(graph[nxt_r][nxt_c] == FIRE || graph[nxt_r][nxt_c] == WALL) continue;
      if(visited[nxt_r][nxt_c]) continue;   

      if(isExit({nxt_r, nxt_c})) { // <- 출구에 다다랐을 때
        min_time = data.second + 1;
        return;
      }

      visited[nxt_r][nxt_c] = 1;
      q.push({{nxt_r, nxt_c}, data.second + 1});
    }
  }
}


void solve() {
  bfs(start);

  if(min_time == INF) cout << "IMPOSSIBLE";
  else cout << min_time;
}

int main() {
  input();
  solve();
  return 0;
}