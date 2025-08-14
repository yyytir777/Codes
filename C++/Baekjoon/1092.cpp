// 1092 cpp
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n, m;
bool visited[MAX] = {0,};
vector<int> crains, boxes;

void input() {
  int tmp;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> tmp;
    crains.push_back(tmp);
  }

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> tmp;
    boxes.push_back(tmp);
  }
}

bool compare(int a, int b) {
  return a > b;
}

bool allVisited() {
  for(int i = 0; i < m; i++) {
    if(!visited[i]) return false;
  }
  return true;
}

void solve() {
  sort(crains.begin(), crains.end(), compare);
  sort(boxes.begin(), boxes.end(), compare);

  if(boxes[0] > crains[0]) {
    cout << "-1";
    return;
  }

  int answer = 0;
  int cnt = 0;

  while(cnt < m) {
    int crain_idx = 0, box_idx = 0;
    while(crain_idx < n && box_idx < m) {

      // box_idx 업데이트
      while(box_idx < m && visited[box_idx]) box_idx++;
      if(box_idx >= m) {
        break;
      } 

      // printf("processing... crain_idx : %d / box_idx : %d\n", crain_idx, box_idx);

      if(crains[crain_idx] >= boxes[box_idx]) {
        visited[box_idx] = 1;
        crain_idx++;
        cnt++;
      }

      box_idx++;
    }
    answer++;
  }

  cout << answer;
}

int main() {
  input();
  solve();
  return 0;
}