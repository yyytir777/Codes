// 1072 cpp 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y;

void solve() {
  cin>>x>>y;
  ll z = ((double)y * 100 / x);
  if(z >= 99) {
    cout << "-1";
    return;
  }

  ll start = 1, end = x;
  while(start <= end) {
    // mid : 몇 번 더 해야하는지
    ll mid = (start + end) / 2;

    ll diff = ((double) (y + mid) * 100 / (x + mid));
    // printf("s : %d, e : %d, mid : %d, diff : %d\n", start, end, mid, diff);
    if(diff <= z) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }
  }
  cout << start;
}

int main() {
  solve();
  return 0;
}