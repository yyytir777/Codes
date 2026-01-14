// 1584 cpp
#include <bits/stdc++.h>
#define INF 987654321
#define MAX 501
#define SAFE 0
#define RISK 1
#define DEATH INF
using namespace std;

typedef pair<int, int> Pair;

int graph[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {0,};
priority_queue<pair<int, Pair>> pq;

int n, m;
int dist[MAX][MAX];

int r_axis[4] = {1, -1, 0, 0};
int c_axis[4] = {0, 0, 1, -1};

void input() {
  cin >> n;
  int x1, y1, x2, y2;
  for(int i = 0; i < n; i++) {
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = min(x1, x2); i <= max(x1, x2); i++) {
      for(int j = min(y1, y2); j <= max(y1, y2); j++) {
        graph[i][j] = RISK;
      }
    }
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = min(x1, x2); i <= max(x1, x2); i++) {
      for(int j = min(y1, y2); j <= max(y1, y2); j++) {
        graph[i][j] = DEATH;
      }
    }
  }
}

void init() {
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      dist[i][j] = INF;
    }
  }
}

bool isRisk(Pair prev, Pair cur) {
  if(graph[prev.first][prev.second] == SAFE &&
    graph[cur.first][cur.second] == RISK) {
    return true;
  }
  return false;
}

bool isDeath(Pair cur) {
  if(graph[cur.first][cur.second] == DEATH) {
    return true;
  }
  return false;
}


void dijkstra() {
  Pair start = {0,0};

  pq.push({0, start});


  while(!pq.empty()) {
    pair<int, Pair> node = pq.top();
    pq.pop();

    int cur_dist = -node.first;
    Pair cur_node = node.second;

    if(cur_node.first == 500 && cur_node.second == 500) {
      return;
    }

    for(int i = 0; i < 4; i++) {
      int nxt_r = cur_node.first + r_axis[i];
      int nxt_c = cur_node.second + c_axis[i];
      int nxt_dist = cur_dist + graph[nxt_r][nxt_c];

      if(nxt_c < 0 || nxt_c >= MAX || nxt_r < 0 || nxt_r >= MAX) continue;

      if(isDeath({nxt_r, nxt_c})) continue;

      if(visited[nxt_r][nxt_c]) continue;

      if(nxt_dist > dist[nxt_r][nxt_c]) continue;

      dist[nxt_r][nxt_c] = nxt_dist;
      pq.push({-nxt_dist, {nxt_r, nxt_c}});
      visited[nxt_r][nxt_c] = 1;
    }
  }
}

void solve() {
  init();
  dijkstra();

  if(dist[500][500] == INF) {
    cout << "-1";
  } else {
    cout << dist[500][500];
  }
}

int main() {
  input();
  solve();
  return 0;
}