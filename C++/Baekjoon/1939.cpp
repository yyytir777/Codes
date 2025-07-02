// 1939 cpp
#include <bits/stdc++.h>
#define MAX 10001
#define MAX_WEIGHT 1000000000
using namespace std;

typedef pair<int, int> Pair;

int n, m, s, e;
int max_weight = 0;

vector<Pair> graph[MAX];
queue<int> q;
bool visited[MAX] = {0,};

void input() {
  cin >> n >> m;

  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    max_weight = max(max_weight, c);
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }

  cin >> s >> e;
}

// w 범위 내로 옮길 수 있는 경로가 있는지 (bool)
bool bfs(int w) {
  q.push(s);
  visited[s] = 1;

  while(!q.empty()) {
    int cur = q.front();
    if(cur == e) return true;
    q.pop();

    for(int i = 0; i < graph[cur].size(); i++) {
      int nxt = graph[cur][i].first;
      int nxt_w = graph[cur][i].second;
      if(!visited[nxt] && w <= nxt_w) {
        q.push(nxt);
        visited[nxt] = 1;
      }
    }
  }
  return false;
}

void init() {
  for(int i = 1; i <= MAX; i++) visited[i] = 0;
  while(!q.empty()) {
    q.pop();
  }
}

void solve() {
  int start = 1, end = max_weight;

  while(start <= end) {
    init();
    int mid = (start + end) / 2;

    if(bfs(mid)) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }

  cout << end;
}

int main() {
  input();
  solve();
  return 0;
}