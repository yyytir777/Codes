// 2075 cpp
#include <bits/stdc++.h>
#include <ios>
#define MAX 1501
using namespace std;

int n;
priority_queue<int> pq;

// 모든 n*n수를 관리하지 않고 n개만 처리
void input() {
  cin >> n;
  int tmp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> tmp;
      pq.push(-tmp);

      if(pq.size() > n) pq.pop();
    }
  }
}

void solve() {
  int answer = -pq.top();
  cout << answer;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  
  input();
  solve();
  return 0;
}