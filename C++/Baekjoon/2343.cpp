#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m, max_video, sum = 0;
int videos[MAX];

void input() {
  cin >> n >> m;

  for(int i = 0; i < n; i++) {
    cin >> videos[i];
  }


  for(int video : videos) {
    max_video = max(max_video, video);
    sum += video;
  }
}

void solve() {
  int start = max_video, end = sum;

  while(start <= end) {
    int mid = (start + end) / 2;
    // printf("%d\n", mid);
    int size = 0, cnt = 1;

    for(int i = 0; i < n; i++) {
      if(size + videos[i] > mid) {
        cnt++;
        size = 0;
      }
      size += videos[i];
    }

    if(cnt > m) {
      start = mid + 1;
    }
    else {
      end = mid - 1;
    }

  }

  cout << start;
}

int main() {
  input();
  solve();
  return 0;
}