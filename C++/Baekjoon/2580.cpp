// 2580 cpp
#include <bits/stdc++.h>
#define BLANK 0
using namespace std;

typedef pair<int, int> Pair;

bool found = false;
int graph[9][9];
vector<Pair> blanks;

void input() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cin >> graph[i][j];
      if(graph[i][j] == 0) blanks.push_back({i,j});
    }
  }
}

void marked(Pair node, int element) {
  graph[node.first][node.second] = element;
}

void unmarked(Pair node) {
  graph[node.first][node.second] = BLANK;
}

void print() {
  for(int i = 0; i < 9; i++) {
    for(int j = 0; j < 9; j++) {
      cout << graph[i][j] << " ";
    }
    cout << '\n';
  }
}


// node의 숫자가 조건을 만족하지 않으면 true, 만족하면 false
bool unconditioned(Pair node) {
  int cur_number = graph[node.first][node.second];
  for(int i = 0; i < 9; i++) {
    if(graph[node.first][i] == cur_number && node.second != i) return true;
    if(graph[i][node.second] == cur_number && node.first != i) return true;
  }

  // node = {1, 4}
  // diff_r = 1, diff_C = 1;
  int diff_r = node.first % 3;
  int diff_c = node.second % 3;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(diff_r == i && diff_c == j) continue;
      if(graph[node.first - diff_r + i][node.second - diff_c + j] == cur_number) return true;
    }
  }

  return false;
}

void dfs(int idx) {
  if(found) return;
  if(idx == blanks.size()) {
    print();
    found = true;
    return;
  }

  Pair cur_node = blanks[idx];
  for(int i = 1; i < 10; i++) {
    graph[cur_node.first][cur_node.second] = i;
    if(unconditioned(cur_node)) {
      graph[cur_node.first][cur_node.second] = 0;
      continue;
    }
    dfs(idx + 1);
    graph[cur_node.first][cur_node.second] = 0;
  }
}

void solve() {
  dfs(0);
}

int main() {
  input();
  solve();
  return 0;
}