// 14427 cpp
#include <bits/stdc++.h>
#include <ios>
#define MAX 100001
#define INF 987654321
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;

int n, m;
// {value, index}
Pair tree[MAX * 4 + 1];
int arr[MAX];

void input() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
}

void init(int start, int end, int node) {
  if(start == end) {
    tree[node] = {arr[start], start};
    return;
  }

  int mid = (start + end) / 2;
  init(start, mid, node * 2);
  init(mid + 1, end, node * 2 + 1);

  if(tree[node * 2].first < tree[node * 2 + 1].first) tree[node] = tree[node * 2];
  else if(tree[node * 2].first > tree[node * 2 + 1].first) tree[node] = tree[node * 2 + 1];
  else {
    tree[node] = (tree[node * 2].second < tree[node * 2 + 1].second) ? tree[node * 2] : tree[node * 2 + 1];
  }
}

Pair update(int idx, int target, int node, int start, int end) {
  if(idx < start || end < idx) return tree[node];
  if(idx == start && idx == end) return tree[node] = {target, idx};
  
  int mid = (start + end) / 2;
  Pair lval = update(idx, target, node * 2, start , mid);
  Pair rval = update(idx, target, node * 2 + 1, mid + 1, end);

  if(lval.first < rval.first) tree[node] = lval;
  else if(lval.first > rval.first) tree[node] = rval;
  else tree[node] = (lval.second < rval.second) ? lval : rval;
  return tree[node];
}

// l, r은 구하려는 범위의 합 & start, end는 현재 함수의 인덱스 범위
// Pair query(int node, int start, int end, int l, int r) {
//   if(r < start || end < l) return {INF,0};
//   if(l <= start && end <= r) return tree[node];

//   int mid = (start + end) / 2;
//   int lval = query(node * 2, start, mid, l, r);
//   int rval = query(node * 2 + 1, mid + 1, end, l, r);

//   if(lval )
//   return lval + rval;
// }

int query() {
  return tree[1].second;
}

void solve() {
  init(1, n, 1);

  cin >> m;
  int a, b, c;
  for(int i = 0; i < m; i++) {
    cin >> a;
    if(a == 1) {
      cin >> b >> c;
      update(b, c, 1, 1, n);
    }
    else {
      cout << query() << '\n';

    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();
  solve();
  return 0;
}