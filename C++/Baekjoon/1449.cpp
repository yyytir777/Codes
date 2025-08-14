// 1449 cpp
#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<int> points;

void input() {
  cin >> n >> l;

  int tmp;
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    points.push_back(tmp);
  }
}

void solve() {
  sort(points.begin(), points.end());

  int point_idx = 0, answer = 0;
  while(point_idx < n) {
    int nxt_point_idx = point_idx;
    while(points[nxt_point_idx] <= points[point_idx] + l - 1) {
      nxt_point_idx++;
    }

    if(points[nxt_point_idx] > points[point_idx] + l - 1) {
      nxt_point_idx--;
    }
    // printf("%d : %d\n", point_idx, nxt_point_idx);
    answer++;
    point_idx = nxt_point_idx + 1;
  }
  cout << answer;
}

int main() {
  input();
  solve();
  return 0;
}