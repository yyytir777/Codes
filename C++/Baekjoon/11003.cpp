// 11003 cpp
#include <bits/stdc++.h>
#include <ios>
#define MAX 5000001
#define INF 2000000000
using namespace std;

int n, l;
int arr[MAX];
deque<pair<int, int>> deq;

void input() {
  cin >> n >> l;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
}

void print_deque() {
  for(auto node : deq) {
    cout << node.first << " : " << node.second << " / ";
  }
  cout << "\n";
}

void solve() {
  for(int i = 1; i <= n; i++) {
    while(!deq.empty() && deq.back().first >= arr[i]) deq.pop_back();
    while(!deq.empty() && deq.front().second <= i - l) deq.pop_front();
    deq.push_back({arr[i], i});
    // print_deque();
    cout << deq.at(0).first << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();
  solve();
  return 0;
}