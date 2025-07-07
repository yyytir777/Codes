// 15652 cpp
#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
bool selected[MAX] = {0,};
vector<int> elements;

void print() {
  for(auto element : elements) {
    cout << element << " ";
  }
  cout << '\n';
}

void dfs(int idx, int depth) {
  if(idx > n || depth >= m) {
    print();
    return;
  }

  for(int i = idx; i <= n; i++) {
    elements.push_back(i);
    dfs(i, depth + 1);
    elements.pop_back();
  }
}

int main() {
  cin >> n >> m;

  dfs(1, 0);

  return 0;
}