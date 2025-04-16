// 13424 cpp
#include <bits/stdc++.h>
#define MAX 101
#define INF 987654321
using namespace std;

typedef pair<int, int> Pair;
int tc;
int n, m, k;
int dist[MAX];
vector<int> friends;
vector<Pair> graph[MAX];
priority_queue<Pair> pq;

void input() {
  cin >> n >> m;

  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }

  cin >> k;
  int tmp;
  for(int i = 0; i < k; i++) {
    cin >> tmp;
    friends.push_back(tmp);
  }
}

void init_dist() {
  for(int i = 0; i <= n; i++) {
    dist[i] = INF;
  }
}


void dijkstra(int start) {
  dist[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    int cur_dist = -pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();

    if(cur_dist > dist[cur_node]) continue;

    for(int i = 0; i < graph[cur_node].size(); i++) {
      int nxt_dist = graph[cur_node][i].second + cur_dist;
      int nxt_node = graph[cur_node][i].first;

      if(nxt_dist < dist[nxt_node]) {
        dist[nxt_node] = nxt_dist;
        pq.push({-nxt_dist, nxt_node});
      }
    }
  }
}

void solve() {
  int total_dist[MAX] = {0,};
  for(int fviend : friends) {
    init_dist();
    dijkstra(fviend);

    for(int i = 1; i <= n; i++) {
      total_dist[i] += dist[i];
    }
  }

  int min_dist = INF;
  for(int i = 1; i <= n; i++) {
    min_dist = min(min_dist, total_dist[i]);
  }

  vector<int> min_idx;
  for(int i = 1; i <= n; i++) {
    if(min_dist == total_dist[i]) {
      min_idx.push_back(i);
    }
  }

  sort(min_idx.begin(), min_idx.end());
  cout << min_idx[0] << '\n';
}

void init() {
  friends.clear();
  for(int i = 0; i <= n; i++) {
    graph[i].clear();
  }
}

int main() {
  cin >> tc;
  while(tc--) {
    init();
    input();
    solve();
  }
  
  return 0;
}