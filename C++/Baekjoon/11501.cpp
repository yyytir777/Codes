// 11501 cpp
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int tc, n;
bool increased[MAX];
vector<int> stocks;

void init() {
  stocks.clear();
  for(int i = 0; i < MAX; i++) {
    increased[i] = 0;
  }
}

void input() {
  cin >> n;

  int tmp;
  for(int i = 0 ; i < n; i++) {
    cin >> tmp;
    stocks.push_back(tmp);
  }
}

void print() {
  for(auto stock : stocks) {
    cout << stock << " ";
  }
  cout << "\n\n";
}

void increase(int s, int e) {
  for(int i = s; i <= e; i++) {
    increased[i] = 1;
  }
}

/* 위에서부터 계산하기...? */
void cal_increase() {
  int max = stocks[n-1];
  for(int i = n-1; i > 0; i--) {
    if(stocks[i-1] > max) {
      max = stocks[i-1];
    }
    else if(stocks[i-1] < max) {
      increased[i-1] = 1;
    }
  }
}

void solve() {
  cal_increase();

  // for(int i = 0; i < n - 1; i++) {
  //   cout << increased[i] << " ";
  // }
  // cout << '\n';

  long long sum = 0;
  int size = 0;
  for(int i = 0; i < stocks.size() - 1; i++) {
    if(!increased[i]) {
      size = 0;
    }
    else if(increased[i]) {
      size++;
      sum += size * (stocks[i+1] - stocks[i]);
    }
  }
  cout << sum << '\n';
}

int main() {
  cin >> tc;
  while(tc--) {
    init();
    input();
    solve();
  }
  return 0;
}