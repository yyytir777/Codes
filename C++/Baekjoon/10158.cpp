// 10158 cpp
#include <bits/stdc++.h>
using namespace std;

int w, h, p, q, t;

void input() {
  cin >> w >> h;
  cin >> p >> q;
  cin >> t;
}

/*

(6, 4) -> 5, 3
t = 4
=> (t - (w - p)) % w
    = (8 - (6 - 4)) % 6 == 0

=> (t - (h - q)) % h
    = (8 - (4 - 1)) % 4 == 1
*/


void solve() {
  int x = (p + t) % (2 * w);
  if (x > w) x = 2 * w - x;

  int y = (q + t) % (2 * h);
  if (y > h) y = 2 * h - y;

  printf("%d %d", x, y);
}

int main() {
  input();
  solve();
  return 0;
}