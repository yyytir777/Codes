// 2212 cpp
#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int n, k;
int arr[MAX];
bool visisted[MAX] = {0,};

int cnt = 1;

void input() {
  cin >> n; cin >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
}

bool compare(int a, int b) {
  return a > b;
}

void solve() {
  sort(arr, arr+n);

  vector<int> dist;
  for(int i = 0; i < n - 1; i++) {
    dist.push_back(abs(arr[i] - arr[i+1]));
  }

  sort(dist.begin(), dist.end());

  int sum = 0;
  for(int i = 0; i < n - k; i++) {
    sum += dist[i];
  }

  cout << sum;
}

int main() {
  input();
  solve();
  return 0;
}