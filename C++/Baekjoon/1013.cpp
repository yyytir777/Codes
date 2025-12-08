// 1013 cpp
#include <bits/stdc++.h>
using namespace std;

int tc;
string wave;

/*

NO
NO

*/
void solve() {
  int status = wave[0] - '0';
  for(int i = 1; i < wave.length(); i++) {
    if(status == 6) {
      cout << "NO\n";
      return;
    }

    if(wave[i] == '0') {
      if(status == 0) status = 6;
      else if(status == 1) status = 2;
      else if(status == 2) status = 4;
      else if(status == 3) status = 0;
      else if(status == 4) status = 4;
      else if(status == 5) status = 0;
      else if(status == 7) status = 8;
      else if(status == 8) status = 4;
    }
    else { // wave[i] == '1'
      if(status == 0) status = 3;
      else if(status == 1) status = 6;
      else if(status == 2) status = 6;
      else if(status == 3) status = 1;
      else if(status == 4) status = 5;
      else if(status == 5) status = 7;
      else if(status == 7) status = 7;
      else if(status == 8) status = 3;
    }
  }

  // cout << "YES\n";
  if(status == 3 || status == 5 || status == 7) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  cin >> tc;
  while(tc--) {
    cin >> wave;
    solve();  
  }
}