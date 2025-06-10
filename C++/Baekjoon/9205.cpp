// 9205 cpp
#include <bits/stdc++.h>
#define MAX 65538
using namespace std;

typedef pair<int, int> Pair;

int n, beers;
bool flag = 0;
Pair home, festival;
vector<Pair> nodes;
queue<Pair> q;
set<Pair> visited;

int dist(Pair a, Pair b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void input() {
  int a, b;
  cin >> n;
  cin >> a >> b;
  home = {a,b};

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    nodes.push_back({a, b});
  }

  cin >> a >> b;
  festival = {a,b};
  nodes.push_back(festival);

}

bool equal(Pair a, Pair b) {
  return a.first == b.first && a.second == b.second;
}

void bfs() {
  beers = 20;
  q.push(home);
  visited.insert(home);

  while(!q.empty()) {
    Pair cur_node = q.front();
    q.pop();

    // printf("(%d, %d)\n", cur_node.first, cur_node.second);
    for(int i = 0; i < nodes.size(); i++) {
      Pair next_pos = nodes[i];
      // 방문하지 않았을 때
      if(visited.find(next_pos) != visited.end()) continue;

      // 맥주를 마실 수 있는 거리에 편의점이 있을 때
      if(dist(cur_node, next_pos) <= beers * 50 && !equal(festival, next_pos)) {
        visited.insert(next_pos);
        q.push(next_pos);
      }

      // 맥주를 마실 수 있는 거리에 페스티벌 장소가 있을 때
      if(dist(cur_node, next_pos) <= beers * 50 && equal(festival, next_pos)) {
        flag = 1;
        return;
      }
    }
  }
}

void solve() {
  bfs();
  if(flag) cout << "happy\n";
  else cout << "sad\n";
}

void init() {
  flag = 0;
  while(!q.empty()) q.pop();
  visited.clear();
  nodes.clear();
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    init();
    input();
    solve();  
  }
}