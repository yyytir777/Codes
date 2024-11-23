#include <bits/stdc++.h>
#define MAX 100

#define CHEEZE 1
#define HOLE_AIR 0
#define AIR 2
using namespace std;

/*
bfs() -> 전체를 순회로 돎
공기를 순회할 때, 구멍속을 만났을 때, 공기로 변하게 하며 순회
치즈를 순회할 때,환치즈만 순회 및 치즈의 개수
치즈의 개수를 반환
*/

int r, c;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};

int row_axis[4] = {0, 0, 1, -1};
int col_axis[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void input() {
    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
}

void print() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

/*
공기를 2로, 구멍 속 공기를 0으로 set하는 과정
*/
void setData() {
    q.push({1, 1});
    visited[1][1] = 1;
    graph[1][1] = AIR;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxt_row = cur_pos.first + row_axis[i];
            int nxt_col = cur_pos.second + col_axis[i];

            if(nxt_row < 0 || nxt_row > r || nxt_col < 0 || nxt_col > c) continue;

            if(graph[nxt_row][nxt_col] == AIR) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
            }
            else if(graph[nxt_row][nxt_col] == HOLE_AIR) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
                graph[nxt_row][nxt_col] = AIR;
            }
        }
    }
}

int bfs(pair<int ,int > start) {
    int cnt = 0;
    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        cnt++;
        q.pop();

        if(adj_with_air()) {
            graph[cur_pos.first][cur_pos.second] = AIR;
        }

        for(int i = 0; i < 4; i++) {
            int nxt_row = cur_pos.first + row_axis[i];
            int nxt_col = cur_pos.second + col_axis[i];

            if(nxt_row < 0 || nxt_row > r || nxt_col < 0 || nxt_col > c) continue;

            if(graph[nxt_row][nxt_col] == CHEEZE  && !visited[nxt_row][nxt_col]) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
            }
        }
    }
}

int melted() {
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] == CHEEZE) {
                cnt += bfs({i, j});
            }
        }
    }
    return cnt;
}

void solve() {
    int time = 0;
    while(true) {
        setData();
        int cheeze_cnt = melted();
        time++;

        if(isAllMelted()) {
            cout << time << '\n' << cheeze_cnt;
            return;
        }
    }
}

int main() {
    input();
    solve();
}