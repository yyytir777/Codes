#include <bits/stdc++.h>
#define MAX 301
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
int dist[MAX][MAX] = {0,};
int row_axis[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int col_axis[8] = {2, 1, -1, -2, -2, -1, 1, 2};
queue<pair<int, int>> q;

void init(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

int bfs(pair<int, int> start, pair<int, int> end, int l) {
    q.push(start);
    visited[start.first][start.second] = 1;

    while(!q.empty()) {
        pair<int, int> cur_pos = q.front();
        q.pop();

        for(int i = 0; i < 8; i++) {
            int next_row = cur_pos.first + row_axis[i];
            int next_col = cur_pos.second + col_axis[i];
            pair<int, int> next_pos = {next_row, next_col};

            // 영역 벗어난 경우
            if(next_row < 0 || next_row >= l || next_col < 0 || next_col >= l) continue;

            // 제대로 이동하는 경우
            if(visited[next_row][next_col] == 0) {
                visited[next_row][next_col] = 1;
                q.push(next_pos);

                if(dist[next_row][next_col] == 0 || dist[next_row][next_col] > dist[cur_pos.first][cur_pos.second] + 1) {
                    dist[next_row][next_col] = dist[cur_pos.first][cur_pos.second] + 1;
                }
            }
        }
    }

    return dist[end.first][end.second];
}

int main() {
    int tc;
    cin >> tc;

    int l;
    pair<int, int> start, end;
    while(tc--) {
        cin >> l;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        init(l);
        cout << bfs(start, end, l) << '\n';
    }
}