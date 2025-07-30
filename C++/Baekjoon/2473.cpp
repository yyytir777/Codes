// 2473 cpp
#include <bits/stdc++.h>
#define MAX 5001
#define INF 3000000000
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> Node;

int n;
Node node;
ll liquid[MAX];

/*

1) 0에 가장 가까운 경우를 선택하기보다,
양수 중 가장 작은 경우 & 음수 중 가장 큰 경우를 나눠
두 수 중 가장 0과 가장 가까운 경우를 선택


2) 

*/

void input() {
  cin >> n;
  int tmp;
  for(int i = 0; i < n; i++) {
    cin >> liquid[i];
  }
}

void solve() {
  ll min_answer = INF;
  sort(liquid, liquid+n);
  int start = 0, end = n - 1;

  for(int i = 0; i < n - 2; i++) {
    int start = i + 1;
    int end = n - 1;

    while(start < end) {
      ll sum = liquid[start] + liquid[end] + liquid[i];
      if(abs(sum) < min_answer) {
        min_answer = abs(sum);
        node = {i, {start, end}};
      }

      if(sum < 0) start++;
      else end--;
    }
  }

  printf("%lld %lld %lld", liquid[node.first], liquid[node.second.first], liquid[node.second.second]);
}

int main() {
  input();
  solve();
  return 0;
}