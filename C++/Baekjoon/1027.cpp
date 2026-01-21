// 1027 cpp
#include <bits/stdc++.h>
#define INF 987654321
#define MAX 51
using namespace std;


typedef long long ll;

int n;
ll buildings[MAX];

void input() {

  cin >> n;
  ll length;
  for(int i = 1; i <= n; i++) {
    cin >> length;
    buildings[i] = length;
  }
}

ll get(int idx) {
  return buildings[idx];
}

/*

b1 + (b2 - b1) / (a2 - a1) * (x - a1)

*/
bool isPossible(int start, int end) {
  if(abs(start - end) == 1) return true; 
  for(int i = start + 1; i < end; i++) {
    double limit = (double) (get(end) - get(start)) * (i - start) / (end - start) + get(start);

    if((double) get(i) >= limit) return false;
  }
  
  return true;
}

int search_left(int cur) {
  int cnt = 0, idx = cur;

  for(int i = 1; i < cur; i++) {
    if(isPossible(i, cur)) cnt++;
  }

  return cnt;
}

int search_right(int cur) {
  int cnt = 0, idx = cur;

  for(int i = cur + 1; i <= n; i++) {
    if(isPossible(cur, i)) cnt++;
  }

  return cnt;
}

void solve() {
  int cnt = 0;
  for(int i = 1; i <= n; i++) {

    int cnt_l = search_left(i);
    int cnt_r = search_right(i);

    // printf("%d : %d\n", i, (cnt_l + cnt_r));
    cnt = max(cnt_l + cnt_r, cnt);
  }

  cout << cnt;
}

void print() {
  for(int i = 1; i <= n; i++) {
    cout << get(i) << "\n";
  }
}

int main() {
  input();
  solve();
  return 0;
}