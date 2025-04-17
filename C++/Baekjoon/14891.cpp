// 14891 cpp
#include <bits/stdc++.h>
#define N 0
#define S 1
using namespace std;

int k;
int chain[4][8];
bool visited[10] = {0,};
vector<pair<int, int>> turn;

void init_visited() {
  for(int i = 0; i < 4; i++) visited[i] = 0;
}

void input() {
  string tmp;
  for(int i = 0; i < 4; i++) {
    cin >> tmp;
    for(int j = 0; j < 8; j++) {
      chain[i][j] = tmp[j];
      chain[i][j] -= 48;
    }
  }

  cin >> k;
  int n, d;
  for(int i = 0; i < k; i++) {
    cin >> n >> d;
    turn.push_back({n, d});
  }
}

void rotate(int n) {
  int tmp = chain[n][7];
  for(int i = 6; i >= 0; i--) {
    chain[n][i+1] = chain[n][i];
  }
  chain[n][0] = tmp;
}

void rotate_reverse(int n) {
  int tmp = chain[n][0];
  for(int i = 1; i < 8; i++) {
    chain[n][i-1] = chain[n][i];
  }
  chain[n][7] = tmp;
}

void move(int n, int d) {
  // n은 번호가 아닌 인덱스로 사용
  if(n < 0 || n > 3) return;

  visited[n] = 1;

  //왼쪽으로 propagation
  if(n - 1 >= 0 && !visited[n-1]) {
    if(chain[n][6] != chain[n-1][2]) {
      move(n - 1, -d);
    }
  }

  //오른쪽으로 propagation
  if(n + 1 <= 3 && !visited[n+1]) {
    if(chain[n][2] != chain[n+1][6]) {
      move(n + 1, -d);
    }
  }

  if(d == 1) {
    rotate(n);
  }
  else {
    rotate_reverse(n);
  }
}

int calculate_score() {
  int score = 0;
  score += chain[0][0] == 0 ? 0 : 1;
  score += chain[1][0] == 0 ? 0 : 2;
  score += chain[2][0] == 0 ? 0 : 4;
  score += chain[3][0] == 0 ? 0 : 8;
  return score;
}

void solve() {
  for(auto node : turn) {
    int num = node.first;
    int direction = node.second;

    init_visited();
    move(num - 1, direction);
  }

  cout << calculate_score();
}

void print() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 8; j++) {
      cout << chain[i][j] << " ";
    }
    cout << '\n';
  }
}

int main() {
  input();
  // print();
  solve();
  return 0;
}