// 14497 cpp
#include <bits/stdc++.h>
#define MAX 301
#define BLANK 0
#define WALL 1
#define TEMP 2
#define ME '*'
#define CHOCOBAR '#'
using namespace std;

typedef pair<int, int> Pair;
int n, m;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};

pair<int, int> chocobar;
pair<int, int> me;

void init() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      visited[i][j] = 0;
    }
  }
}

void input() {
  cin >> n >> m;

  cin >> me.first >> me.second;
  cin >> chocobar.first >> chocobar.second;

  string tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    for(int j = 0; j < m; j++) {
      if(tmp[j] == ME) graph[i+1][j+1]= BLANK;
      else if(tmp[j] == CHOCOBAR) graph[i+1][j+1] = BLANK;
      else graph[i+1][j+1] = tmp[j] - '0';
    }
  }
}

int r_axis[4] = {0, 0, 1, -1};
int c_axis[4] = {1, -1, 0, 0};

bool isConnected() {
  init();
  Pair start = me;
  queue<Pair> q;

  q.push(start);
  visited[start.first][start.second] = 1;

  while(!q.empty()) {
    Pair cur_node = q.front();
    q.pop();

    if(cur_node.first == chocobar.first && cur_node.second == chocobar.second) {
      return true;
    }

    for(int i = 0; i < 4; i++) {
      int nxt_r = cur_node.first + r_axis[i];
      int nxt_c = cur_node.second + c_axis[i];

      if(nxt_r <= 0 || nxt_r > n || nxt_c <= 0 || nxt_c > m) continue;

      if(visited[nxt_r][nxt_c]) continue;

      if(graph[nxt_r][nxt_c] == WALL) continue;

      if(graph[nxt_r][nxt_c] == BLANK) {
        visited[nxt_r][nxt_c] = 1;
        q.push({nxt_r,nxt_c});
      }
    }
  }

  return false;
} 

void wave() {
  init();
  Pair start = me;
  queue<Pair> q;

  q.push(start);
  visited[start.first][start.second] = 1;

  while(!q.empty()) {
    Pair cur_node = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nxt_r = cur_node.first + r_axis[i];
      int nxt_c = cur_node.second + c_axis[i];

      if(nxt_r <= 0 || nxt_r > n || nxt_c <= 0 || nxt_c > m) continue;

      if(visited[nxt_r][nxt_c]) continue;

      if(graph[nxt_r][nxt_c] == WALL) {
        graph[nxt_r][nxt_c] = TEMP;
      }

      if(graph[nxt_r][nxt_c] == BLANK) {
        visited[nxt_r][nxt_c] = 1;
        q.push({nxt_r,nxt_c});
      }
    }
  }
}

void convertTempToBlank() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(graph[i][j] == TEMP) graph[i][j] = BLANK;
    }
  }
}

void print() {
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cout << graph[i][j] << " ";
    }
    cout << '\n';
  }
}

void solve() {
  int cnt = 0;

  while(!isConnected()) {
    wave();
    convertTempToBlank();
    cnt++;
  }
  cout << cnt + 1;
}


int main() {
  input();
  solve();
  return 0;
}