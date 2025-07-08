// 15651 cpp
#include <bits/stdc++.h>
#define MAX 8
using namespace std;

int n, m;
vector<int> elements;

void print() {
  for(int element : elements) {
    cout << element << " ";
  }
  cout << "\n";
}

void dfs(int idx, int depth) {
  if(idx > n || depth >= m) {
    print();
    return;
  }

  for(int i = 1; i <= n; i++) {
    elements.push_back(i);
    dfs(idx + 1, depth + 1);
    elements.pop_back();
  }
}

int main() {
  cin >> n >> m;

  dfs(0,0);

  return 0;
}