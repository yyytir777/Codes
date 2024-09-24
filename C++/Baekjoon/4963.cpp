#include <bits/stdc++.h>
#define MAX 51
#define LAND 1
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int>> q;

int row_axis[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int col_axis[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void init_visited(int w, int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            visited[i][j] = 0;
        }
    }
}

void bfs(pair<int, int> pos, int w, int h) {
    q.push(pos);
    visited[pos.first][pos.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int next_row = cur_pos.first + row_axis[i];
            int next_col = cur_pos.second + col_axis[i];
            pair<int, int> next_pos = {next_row, next_col};

            if(next_row < 0 || next_row >= h || next_col < 0 || next_col >= w) continue;

            if(graph[next_row][next_col] == LAND && visited[next_row][next_col] == 0) {
                visited[next_row][next_col] = 1;
                q.push(next_pos);
            }
        }
    }
}

int main() {
    int w, h;
    while(true) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> graph[i][j];
            }
        }
        
        int cnt = 0;
        init_visited(w, h);

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(graph[i][j] == LAND && visited[i][j] == 0) {
                    bfs({i, j}, w, h); cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}