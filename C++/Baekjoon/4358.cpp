// 4358 cpp
#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
map<string, int> trees;
vector<string> treeName;
map<string, float> ratios;

void input() {
  string tmp;

  while(true) {
    getline(cin, tmp);
    if(tmp.empty()) break;
    cnt++;
    if(trees.find(tmp) == trees.end()) {
      trees.insert({tmp, 1});
    } else {
      trees[tmp]++;
    }
  }
}

void solve() {
  for(auto tree : trees) {
    float ratio = (float) tree.second / cnt * 100;
    ratios.insert({tree.first, ratio});
  }

  sort(treeName.begin(), treeName.end());

  for(auto ratio : ratios) {
    cout << ratio.first;
    printf(" %0.4f\n", ratio.second);
  }
}

void print() {
  for(auto tree : trees) {
    cout << tree.first << " : " << tree.second << "\n";
  }
}

int main() {
  input();
  solve();
  // print();
  return 0;
}