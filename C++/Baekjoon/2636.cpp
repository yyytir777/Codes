#include <bits/stdc++.h>
#define MAX 101

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
bool check_melt_point[MAX][MAX] = {0,};
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

void init() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            visited[i][j] = 0;
        }
    }
}

/*
공기를 2로, 구멍 속 공기를 0으로 set하는 과정
*/
void setData() {
    q.push({0, 0});
    visited[0][0] = 1;
    graph[0][0] = AIR;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nxt_row = cur_pos.first + row_axis[i];
            int nxt_col = cur_pos.second + col_axis[i];

            if(nxt_row < 0 || nxt_row > r || nxt_col < 0 || nxt_col > c) continue;

            if(graph[nxt_row][nxt_col] == AIR && !visited[nxt_row][nxt_col]) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
            }
            else if(graph[nxt_row][nxt_col] == HOLE_AIR && !visited[nxt_row][nxt_col]) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
                graph[nxt_row][nxt_col] = AIR;
            }
        }
    }
}

bool adj_with_air(pair<int, int> pos) {
    for(int i = 0; i < 4; i++) {
        int row = pos.first + row_axis[i];
        int col = pos.second + col_axis[i];

        if(graph[row][col] == AIR) {
            check_melt_point[pos.first][pos.second] = 1;
            return true;
        }
    }
    return false;
}

void bfs(pair<int ,int > start) {
    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        adj_with_air(cur_pos);

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

void update_melted_point() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(check_melt_point[i][j] == 1) {
                graph[i][j] = AIR;
            }
        }
    }
}

void melted() {
    init();
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] == CHEEZE && !visited[i][j]) {
                bfs({i, j});
            }
        }
    }
    update_melted_point();
}

bool isAllMelted() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] == CHEEZE) return false;
        }
    }
    return true;
}

int count_cheeze() {
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(graph[i][j] == CHEEZE) cnt++;
        }
    }
    return cnt;
}

void solve() {
    int time = 0;
    while(true) {
        int cheeze_cnt = count_cheeze();
        init();
        setData();
        init();
        melted();
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