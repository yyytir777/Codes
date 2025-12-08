// 2251 cpp
#include <bits/stdc++.h>
#define MAX 201
using namespace std;

struct Node {
  int a;
  int b;
  int c;
};

int a, b, c;

bool visited[MAX][MAX][MAX];
set<int> s;

vector<Node> getNextNodes(Node cur) {
  vector<Node> v;
  int na, nb, nc;

  // A -> B
  int move = min(cur.a, b - cur.b);
  v.push_back(Node({cur.a - move, cur.b + move, cur.c}));

  // A -> C
  move = min(cur.a, c - cur.c);
  v.push_back(Node({cur.a - move, cur.b, cur.c + move}));

  // B -> A
  move = min(cur.b, a - cur.a);
  v.push_back(Node({cur.a + move, cur.b - move, cur.c}));

  // B -> C
  move = min(cur.b, c - cur.c);
  v.push_back(Node({cur.a, cur.b - move, cur.c + move}));

  // C -> A
  move = min(cur.c, a - cur.a);
  v.push_back(Node({cur.a + move, cur.b, cur.c - move}));

  // C -> B
  move = min(cur.c, b - cur.b);
  v.push_back(Node({cur.a, cur.b + move, cur.c - move}));

  return v;
}

void dfs(Node node) {
  queue<Node> q;
  visited[node.a][node.b][node.c] = 1;
  q.push(node);

  while(!q.empty()) {
    Node curNode = q.front();
    q.pop();

    if(curNode.a == 0) {
      s.insert(curNode.c);
    }

    vector<Node> nxtNodes = getNextNodes(curNode);
    for(Node node : nxtNodes) {
      if(!visited[node.a][node.b][node.c]) {
        visited[node.a][node.b][node.c] = 1;
        q.push(node);
      }
    }  
  }
}

void solve() {
  dfs(Node({0, 0, c}));
  for(auto node : s) {
    cout << node << " ";
  }
}

int main() {
  cin >> a >> b >> c;
  solve();
  return 0;
}