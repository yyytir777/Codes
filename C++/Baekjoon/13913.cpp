// 13913 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

typedef pair<int, int> Pair;

int n, k;
int t[MAX] = {0,};
bool visited[MAX] = {0,};
int v[MAX] = {0,};
queue<int> q;
int min_t = 0;

void input() {
  cin >> n >> k;

}

void bfs(int start) {
  q.push(start);
  visited[start] = 1;
  t[start] = 0;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    if(cur == k) {
      cout << t[cur] << '\n';
      min_t = t[cur];
      return;
    }


    if(cur + 1 < MAX && !visited[cur + 1]) {
      q.push(cur + 1);
      t[cur + 1] = t[cur] + 1;
      visited[cur + 1] = 1;
      v[cur + 1] = cur;
    }

    if(cur - 1 >= 0 && !visited[cur - 1]) {
      q.push(cur - 1);
      t[cur - 1] = t[cur] + 1;
      visited[cur - 1] = 1;
      v[cur - 1] = cur;
    }

    if(2 * cur < MAX && !visited[2 * cur]) {
      q.push(2 * cur);
      t[2 * cur] = t[cur] + 1;
      visited[2 * cur] = 1;
      v[2 * cur] = cur;
    }
  }
}

void print() {
  vector<int> result;

  int idx = k;
  result.push_back(idx);
  for(int i = 0; i < min_t; i++) {
    idx = v[idx];
    result.push_back(idx);
  }

  reverse(result.begin(), result.end());
  for(int node : result) {
    cout << node << " ";
  }
}

void solve() {
  bfs(n);
  print();
}

int main() {
  input();
  solve();
  return 0;
}