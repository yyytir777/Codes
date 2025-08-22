// 10216 cpp
#include <bits/stdc++.h>
#define MAX 3001
#define GRID_MAX 5001
using namespace std;

typedef pair<int, int> Pair;

int tc, n;
int parent[MAX];
vector<pair<Pair, int>> pos;
bool visited[MAX] = {0,};

void init() {
  for(int i = 0; i < n; i++) {
    parent[i] = i;
    visited[i] = 0;
  }
  pos.clear();
}

// n의 루트 parent를 찾는 함수
int find(int n) {
  if(parent[n] == n) return n;
  return find(parent[n]);
}

void union_find(int a, int b) {
  int root_a = find(a);
  int root_b = find(b);

  if(root_a < root_b) {
    parent[root_b] = root_a;
  }
  else {
    parent[root_a] = root_b;
  }
}

void input() {
  cin >> n;

  init();
  int x, y, r;
  for(int j = 0; j < n; j++) {
    cin >> x >> y >> r;
    pos.push_back({{x,y},r});
  }
}

bool isAdj(int a, int b) {
  auto pos_a = pos[a];
  auto pos_b = pos[b];

  int dx = pos_a.first.first - pos_b.first.first;
  int dy = pos_a.first.second - pos_b.first.second;
  double dist = sqrt(dx * dx + dy * dy);

  if(dist <= pos_a.second + pos_b.second) return true;
  else return false;
}

int get_count() {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(find(i) == i) cnt++;
  }
  return cnt;
}

void print_parent() {
  for(int i = 0; i < n; i++) {
    printf("%d -> %d\n", i, parent[i]);
  }
}

void solve() {
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      if(i == j) continue;

      if(isAdj(i, j)) {
        union_find(i, j);
      }
    }
  }

  // print_parent();
  cout << get_count() << '\n';
}

int main() {
  cin >> tc;
  for(int i = 0; i < tc; i++) {
    input();
    solve();  
  }
}