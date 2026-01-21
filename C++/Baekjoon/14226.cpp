// 14226 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int s;
bool visited[MAX * 3][2] = {0,};

struct Node {
  int cnt;
  bool is_copied;
  int copied_cnt;
};

void bfs() {
  queue<pair<Node, int>> q;
  q.push({Node({1, false, 0}), 0});
  visited[1][false] = 1;

  while(!q.empty()) {
    Node cur = q.front().first;
    int dist = q.front().second;

    q.pop();

    if(cur.cnt == s) {
      cout << dist;
      return; 
    }

    Node nextNode;

    // 이모티콘을 복사해서 클립보드에 저장
    nextNode = Node({cur.cnt, 1, cur.cnt});
    if(!visited[nextNode.cnt][nextNode.is_copied]) {
      visited[nextNode.cnt][nextNode.is_copied] = 1;
      q.push({nextNode, dist + 1});
    }

    // 클립보드의 이모티콘을 복사 붙여넣기
    if(cur.is_copied) {
      if(cur.cnt + cur.copied_cnt > s) continue;
      nextNode = Node({cur.cnt + cur.copied_cnt, 1, cur.copied_cnt});
      if(!visited[nextNode.cnt][nextNode.is_copied]) {
        q.push({nextNode, dist + 1});
      }
    }
    
    // 화면에 있는 이모티콘 중 하나를 삭제
    if(cur.cnt - 1 < 0) continue;
    nextNode = Node({cur.cnt - 1, cur.is_copied, cur.copied_cnt});
    if(!visited[nextNode.cnt][nextNode.is_copied]) {
      q.push({nextNode, dist + 1});
    }
  }
}

void solve() {
  bfs();
}

int main() {
  cin >> s;
  solve();
  return 0;
}