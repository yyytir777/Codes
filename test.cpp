// 1719 cpp
#include <bits/stdc++.h>
#define MAX 201
#define INF 987654321
using namespace std;

typedef pair<int, int> Pair;

int n, m;
vector<Pair> graph[MAX];
priority_queue<Pair> pq;
int dist[MAX];
int next_arr[MAX];

void input() {
  cin >> n >> m;

  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
    graph[b].push_back({a,c});
  }
}

void dijkstra(int start) {
  dist[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    // { 거리, 노드 }
    Pair cur = pq.top();
    int cur_dist = -cur.first;
    int cur_node = cur.second;
    pq.pop();

    if(dist[cur_node] < cur_dist) continue;

    for(int i = 0; i < graph[cur_node].size(); i++) {
      int nxt_node = graph[cur_node][i].first;
      int nxt_dist = graph[cur_node][i].second + cur_dist;

      if(dist[nxt_node] > nxt_dist) {
        next_arr[nxt_node] = cur_node;
        dist[nxt_node] = nxt_dist;
        pq.push({-nxt_dist, nxt_node});
      }
    }
  }
}

void init() {
  for(int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
}

void solve() {
  for(int i = 1; i <= n; i++) {
    init();
    // i노드에서 출발하는 최단거리 구함
    dijkstra(i);

    for(int j = 1; j <= n; j++) {
      if(i == j) {
        cout << "-" << " ";
      }
      else if (next_arr[j] == i) {
        cout << j << " ";
      }
      else {
        int num = j;
        while(true) {
          if(next_arr[num] == i) {
            cout << num << " ";
            break;
          } else {
            num = next_arr[num];
          }
        }
      }
    }
    cout << "\n";
  }
}

int main() {
  input();
  solve();
  return 0;
}