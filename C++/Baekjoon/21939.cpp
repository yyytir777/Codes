// 21939 cpp
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
int n;
set<Pair> s;
map<int, int> pindex;

bool compare(Pair a, Pair b) {
  if(a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int p, l, x;
  for(int i = 0; i < n; i++) {
    cin >> p >> l;
    s.insert({l,p});
    pindex[p] = l;
  }


  int m; cin >> m;
  string tmp;
  for(int i = 0; i < m; i++) {
    cin >> tmp;

    if(tmp == "add") {
      cin >> p >> l;
      s.insert({l,p});
      pindex[p] = l;
    }

    else if(tmp == "recommend") {
      cin >> x;
      if(x == 1) {
        cout << s.rbegin()->second << '\n';
      }
      else if(x == -1) {
        cout << s.begin()->second << '\n';
      }
    }

    else if(tmp == "solved") {
      cin >> p;
      s.erase({pindex[p], p});
      pindex.erase(p);
    }
  }
  return 0;
}