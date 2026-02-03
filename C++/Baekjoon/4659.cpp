// 4659 cpp
#include <bits/stdc++.h>
using namespace std;

string pwd;
char vowels[] = {'a', 'e', 'i', 'o', 'u'};
bool flag;


bool hasVowel() {
  for(int i = 0; i < pwd.size(); i++) {
    for(char v : vowels) {
      if(pwd[i] == v) return true;
    }
  }
  return false;
}

bool isRecur() {
  int cnt = 1;
  bool prevIsVowel = 0; // 모음이면 1, 자음이면 0

  for(char v : vowels) {
    if(pwd[0] == v) {
      prevIsVowel = 1;
      break;
    }
  }
  
  for(int i = 1; i < pwd.size(); i++) {
    bool curIsVowel = 0;

    for(char v : vowels) {
      if(pwd[i] == v) {
        curIsVowel = 1;
        break;   
      }
    }

    if(curIsVowel == prevIsVowel) {
      cnt++;
      if(cnt >= 3) return true;
    }
    else {
      cnt = 1;
      prevIsVowel = curIsVowel;
    }
  }

  return false;
}

bool hasSameLetter() {
  for(int i = 1; i < pwd.size(); i++) {
    if(pwd[i] == pwd[i-1] && (pwd[i] != 'o' && pwd[i] != 'e')) {
      return true;
    }
  }
  return false;
}

void solve() {
  flag = 0;
  if(!hasVowel()) return;
  if(isRecur()) return;
  if(hasSameLetter()) return;
  flag = 1;
}

int main() {
  while(cin >> pwd && pwd != "end") {
    solve();

    // 통과 
    if(flag) {
      printf("<%s> is acceptable.\n", pwd.c_str());
    }
    else {
      printf("<%s> is not acceptable.\n", pwd.c_str());
    }
  }
}