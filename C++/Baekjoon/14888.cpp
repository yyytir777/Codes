// 14888 cpp
#include <bits/stdc++.h>
#define MAX 12
using namespace std;

int n, max_result = -1000000001, min_result = 1000000001;
int arr[MAX];
string cal[4] = {"p", "m", "mul", "d"};
string ordered_cal[MAX];
map<string, int> cal_map;

void print() {
  for(int i = 1; i <= n; i++) {
    cout << ordered_cal[i] << " ";
  }
  cout << "\n";
}

int calculate() {
  int sum = 0;
  for(int i = 1; i < n; i++) {
    if(ordered_cal[i] == "p") {
      if(i == 1) sum = arr[i] + arr[i+1];
      else sum += arr[i+1];
    }
    else if(ordered_cal[i] == "m") {
      if(i == 1) sum = arr[i] - arr[i+1];
      else sum -= arr[i+1];
    }
    else if(ordered_cal[i] == "mul") {
      if(i == 1) sum = arr[i] * arr[i+1];
      else sum *= arr[i+1];
    }
    else if(ordered_cal[i] == "d") {
      if(i == 1) sum = arr[i] / arr[i+1];
      else sum /= arr[i+1];
    }
  }
  return sum;
}

void dfs(int idx, int depth) {
  if(idx > n || depth >= n - 1) {
    int num = calculate();
    max_result = max(num, max_result);
    min_result = min(num, min_result);
    return;
  }

  for(int i = 0; i < 4; i++) {
    string inst = cal[i];
    if(cal_map[inst] == 0) continue;
    ordered_cal[idx + 1] = inst;
    cal_map[inst]--;
    dfs(idx + 1, depth + 1);
    cal_map[inst]++;
  }
}

void solve() {
  dfs(0,0);
  cout << max_result << "\n" << min_result;
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> arr[i];
  }

  for(int i = 0; i < 4; i++) {
    cin >> cal_map[cal[i]];
  }

  solve();
  return 0;
}