// 15649 cpp
#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
bool selected[MAX] = {0,};
vector<int> selected_elements;

void print() {
  for(int e : selected_elements) {
    cout << e << " ";
  }
  cout << '\n';
}

void dfs(int idx, int depth) {
  if(selected_elements.size() >= m || idx > n) {
    print();
    return;
  }

  for(int i = 1; i <= n; i++) {
    if(selected[i] == 0) {
      selected_elements.push_back(i);
      selected[i] = 1;
      dfs(i, depth + 1);
      selected[i] = 0;
      selected_elements.pop_back();
    }
  }
}

int main() {
  cin >> n >> m;
  dfs(0, 0);
  return 0;
}