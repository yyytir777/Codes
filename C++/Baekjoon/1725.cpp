// 1725 cpp
#include <bits/stdc++.h>
#define MAX 100001
#define INF 987654321
using namespace std;

typedef pair<int, int> Pair;

int n;
int result = 0;
int arr[MAX];
Pair tree[MAX * 4 + 1]; // 주어진 범위에서 가장 낮은 값 리턴

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> arr[i];
}

// tree = {가장 낮은 높이, 이때의 인덱스}
// idx: tree의 인덱스, start & end: arr에서의 인덱스
void init(int idx, int start, int end) {
  if(start == end) {
    tree[idx] = {arr[start], start};
    return;
  }

  int mid = (start + end) / 2;
  init(idx * 2, start, mid);
  init(idx * 2 + 1, mid + 1, end);
  tree[idx] = tree[idx * 2].first > tree[idx * 2 + 1].first ? tree[idx * 2 + 1] : tree[idx * 2];
  return;
}


// 주어진 범위에서(l,r) 가장 낮은 높이 및 이때의 인덱스 반환 {}
Pair query(int idx, int start, int end, int l, int r) {
  if(start > r || end < l) return {INF, 0};
  if(start >= l && end <= r) return tree[idx];

  int mid = (start + end) / 2;
  Pair lval = query(idx * 2, start, mid, l, r);
  Pair rval = query(idx * 2 + 1, mid + 1, end, l, r);

  if(lval.first == INF) return rval;
  else if(rval.first == INF) return lval;
  else return lval.first < rval.first ? lval : rval;
}

void getMaxArea(int start, int end) {
  if(start > end) return;
  Pair minNode = query(1, 1, n, start, end);
  int area = (end - start + 1) * minNode.first;
  result = max(result, area);

  getMaxArea(start, minNode.second - 1);
  getMaxArea(minNode.second + 1, end);
}

void solve() {
  init(1, 1, n);
  getMaxArea(1, n);
  cout << result;
}

int main() {
  input();
  solve();
  return 0;
}