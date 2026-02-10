// 17609 cpp
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

vector<char> str;


int t;

string getString(vector<char> &v) {
  string s = "";
  for(char c : v) {
    s += c;
  }
  return s;
}

bool isPalindrome(vector<char> &v, int s, int e) {
  while(s < e) {
    if(v[s] == v[e]) s++, e--;
    else return false;
  }
  return true;
}

bool isSemiPalindrome(vector<char> &v) {
  int skipCnt = 0;
  int s = 0, e = v.size() - 1;
  while(s < e) {
    if(v[s] == v[e]) s++, e--;
    else {
      return isPalindrome(v, s+1, e) | isPalindrome(v, s, e-1);
    }
  }
  return false;
}

void solve() {
  if(isPalindrome(str, 0, str.size() - 1)) {
    cout << "0" << '\n';
    return;
  }
  else if(isSemiPalindrome(str)) {
    cout << "1" << '\n';
    return;
  }
  else {
    cout << "2" << '\n';
    return;
  }
}

int main() {
  cin >> t;
  string tmp;
  while(t--) {
    str.clear();
    cin >> tmp;
    for(int i = 0; i < tmp.size(); i++) {
      str.push_back(tmp[i]);
    }
    solve();
  }
  return 0;
}