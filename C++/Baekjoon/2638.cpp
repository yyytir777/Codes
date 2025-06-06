// 2638 cpp
#include <bits/stdc++.h>
#define BLANK 2
#define CHEEZE 1
#define HOLE 0
#define MAX 101
using namespace std;

typedef pair<int, int> Pair;

int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
queue<Pair> q;
vector<Pair> cheezes;

int r_axis[4] = {0, 0, 1, -1};
int c_axis[4] = {1, -1, 0, 0};

void input() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> graph[i][j];
    }
  }
}

bool isEmpty() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(graph[i][j] == CHEEZE) return false;
    }
  }
  return true;
}

void bfs(Pair start) {
  q.push(start);
  graph[start.first][start.second] = BLANK;
  visited[start.first][start.second] = 1;

  while(!q.empty()) {
    Pair cur_node = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nr = cur_node.first + r_axis[i];
      int nc = cur_node.second + c_axis[i];

      if(nr < 0 || nr > n || nc < 0 || nc > m) continue;
      if(visited[nr][nc]) continue;
      if(graph[nr][nc] == CHEEZE) continue;
      if(graph[nr][nc] == HOLE) graph[nr][nc] = BLANK;
      if(graph[nr][nc] == BLANK) {
        q.push({nr, nc});
        visited[nr][nc] = 1;
      }
    }
  }
}

void init() {
  cheezes.clear();
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      visited[i][j] = 0;
    }
  }
}

void checkBlank() {
  bfs({0,0});
}

void findFreezeCheeze() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {

      int cnt = 0, ni, nj;
      for(int k = 0; k < 4; k++) {
        ni = i + r_axis[k];
        nj = j + c_axis[k];
        if(ni < 0 || ni > n || nj < 0 || nj > m) continue;
        if(graph[ni][nj] == BLANK) cnt++;
      }

      if(cnt >= 2) cheezes.push_back({i,j});
    }
  }
}

void freezeCheeze() {
  for(auto node : cheezes) {
    graph[node.first][node.second] = BLANK;
  }
}

void print() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << graph[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() {
  int time = 0;
  while(!isEmpty()) {
    checkBlank(); // 외부 공기를 2로 변경
    init();
    findFreezeCheeze(); // 녹을 예정의 치즈를 선택
    freezeCheeze(); // 치즈를 녹임
    time++;
  }
  cout << time;
}

int main() {
  input();
  solve();
  return 0;
}