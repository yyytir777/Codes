// 1516 cpp
#include <bits/stdc++.h>
#define MAX 501
#define INF 987654321
using namespace std;

int n;
int t[MAX];
int dist[MAX] = {0,};
int degree[MAX] = {0,};
vector<int> parent[MAX];
queue<int> q;

void init_dist() {
  for(int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
}

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> t[i];

    int tmp;
    while(cin >> tmp && tmp != -1) {
      parent[tmp].push_back(i);
      degree[i]++;
    }
  }
}

void topology() {
  for(int i = 1; i <= n; i++) {
    if(!degree[i]) {
      q.push(i);
      dist[i] = t[i];
    }
  }

  while(!q.empty()) {
    int node = q.front();
    q.pop();

    for(int i = 0; i < parent[node].size(); i++) {
      int next = parent[node][i];
      if(dist[next] < dist[node] + t[next]) {
        dist[next] = dist[node] + t[next];
      }
      degree[next]--;
      if(!degree[next]) q.push(next);
    }
  }
}

void solve() {
  topology();

  for(int i = 1; i <= n; i++) {
    cout << dist[i] << '\n';
  }
}

void print() {
  for(int i = 1; i <= n; i++) {
    cout << t[i] << " ";
    // for(int node : parent[i]) {
    //   printf("%d -> %d\n", node, i);
    // }
  }
}

int main() {
  input();
  solve();
  // print();
  return 0;
}