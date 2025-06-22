// 1269 cpp
#include <bits/stdc++.h>
using namespace std;

int a, b;
map<int, int> cnt;

void input() {

}

void solve() {

}

int main() {
  cin >> a >> b;

  int tmp;
  for(int i = 0; i < a; i++) {
    cin >> tmp;
    cnt[tmp] = 1;
  }

  for(int i = 0; i < b; i++) {
    cin >> tmp;

    // tmp 값이 존재하면 삭제
    if(cnt.find(tmp) != cnt.end()) {
      cnt.erase(tmp);
    }
    else cnt[tmp] = 1;
  }

  cout << cnt.size();
  return 0;
}