// 4256 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

typedef vector<int>::iterator it;

int n;
vector<int> preorder(MAX, 0);
vector<int> inorder(MAX, 0);

void init() {
  preorder.clear();
  inorder.clear();
}

void input() {
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> preorder[i];
  }

  for(int i = 1; i <= n; i++) {
    cin >> inorder[i];
  }
}

void getTree(it pre_s, it pre_e, it in_s, it in_e, int idx) {
  if(pre_s > pre_e || in_s > in_e) return;

  int leftSize;
  it iter;
  for(iter = in_s; iter <= in_e; iter++) {
    if(*iter == *pre_s) {
      leftSize = iter - in_s;
      break;
    }
  }

  getTree(pre_s + 1, pre_s + leftSize, in_s, iter - 1, idx * 2);
  getTree(pre_s + 1 + leftSize, pre_e, iter + 1, in_e, idx * 2 + 1);

  cout << *pre_s << " ";
}


void solve() {
  getTree(preorder.begin() + 1, preorder.begin() + n, inorder.begin() + 1, inorder.begin() + n, 1);
  cout << '\n';
}

int tc;

int main() {
  cin >> tc;
  while(tc--) {
    init();
    input();
    solve();
  }
  return 0;
}