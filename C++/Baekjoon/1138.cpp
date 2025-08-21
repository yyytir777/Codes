// 1138 cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

int n;
deque<Pair> height;

void input() {
  cin >> n;

  int tmp;
  for(int i = 1; i <= n; i++) {
    cin >> tmp;
    height.push_back({tmp, i}); // {num, idx}
  }
}

bool compare(Pair a, Pair b) {
  if(a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

void decrease(int length) {

  for(auto& node : height) {
    if(node.first != 0 && length > node.second) {
      node = {node.first - 1, node.second};
    }
  }
}

void print() {
  for(auto node : height) {
    printf("%d ", node.first);
  }
  cout << '\n';
}

void solve() {
  for(int i = 0; i < n; i++) {
    // print();
    sort(height.begin(), height.end(), compare);
    int answer = height.front().second;
    cout << answer << " ";
    height.pop_front();
    decrease(answer);
  }
}

int main() {
  input();
  solve();
  return 0;
}