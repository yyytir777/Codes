// 3197 cpp
#include <bits/stdc++.h>
#define MAX 1500
#define SWAN 'L'
#define ICE 'X'
#define WATER '.'
using namespace std;

// 답은 맞는데 2%에서 시간초과 -> 최적화 방향 생각하기

typedef pair<int, int> Pair;

int r,c;
char graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
vector<Pair> swan_pos;
queue<Pair> waters, next_waters;
queue<Pair> swans, next_swans;

int r_axis[4] = {0, 0, -1, 1};
int c_axis[4] = {1, -1, 0, 0};

void input() {
  cin >> r >> c;

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> graph[i][j];

      if(graph[i][j] == SWAN) {
        swan_pos.push_back({i,j});
        graph[i][j] = WATER;
      }

      // water일때 queue에 추가
      if(graph[i][j] == WATER) {
        bool is_boundary = false;
        for(int d = 0; d < 4; d++) {
            int next_r = i + r_axis[d];
            int next_c = j + c_axis[d];
            if(next_r >= 0 && next_r < r && next_c >= 0 && next_c < c && graph[next_r][next_c] == ICE) {
                is_boundary = true;
                break;
            }
        }
        if(is_boundary) {
          waters.push({i,j});
        }
      }
    }
  }

  swans.push(swan_pos[0]);
  visited[swan_pos[0].first][swan_pos[0].second] = 1;
}

bool isConnected() {
  Pair target = swan_pos[1];

  while(!swans.empty()) {
    Pair cur = swans.front();
    swans.pop();

    for(int i = 0; i < 4; i++) {
      int nr = cur.first + r_axis[i];
      int nc = cur.second + c_axis[i];

      if(nr == target.first && nc == target.second) {
        return true;
      }

      if(visited[nr][nc]) continue;

      if(nr < 0 || nr >= r || nc < 0 || nc >= c) continue;

      if(graph[nr][nc] == ICE && !visited[nr][nc]) {
        next_swans.push({nr, nc});
        visited[nr][nc] = 1;
      }

      if(!visited[nr][nc] && graph[nr][nc] == WATER) {
        swans.push({nr, nc});
        visited[nr][nc] = 1;
      }
    }
  }

  return false;
}

// queue를 사용해 melting 진행 -> brute force 할 필요 없음
// melting 중 ice를 만나면 next_water_queue에 저장
void melting() {
  while(!waters.empty()) {
    Pair cur = waters.front();
    waters.pop();

    for(int i = 0; i < 4; i++) {
      int next_r = cur.first + r_axis[i];
      int next_c = cur.second + c_axis[i];

      if(next_r < 0 || next_r >= r || next_c < 0 || next_c >= c) continue;

      if(graph[next_r][next_c] == ICE) {
        graph[next_r][next_c] = WATER;
        next_waters.push({next_r, next_c});
      }
    }
  }

  waters = next_waters;
  while(!next_waters.empty()) next_waters.pop();
}

void solve() {
  int cnt = 0;
  while(!isConnected()) {
    melting();
    cnt++;

    swans = next_swans;
    while(!next_swans.empty()) next_swans.pop();
  }
  cout << cnt;
}

int main() {
  input();
  solve();
  return 0;
}