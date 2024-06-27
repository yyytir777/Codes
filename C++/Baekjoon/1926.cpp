#include <bits/stdc++.h>
#define MAX 501
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX] = {0,};
queue<pair<int, int>> q;

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};

int cnt, max_size = 0;
int n, m;

int bfs(int i, int j) {
    int size = 1;
    q.push({i, j});
    visited[i][j] = 1;

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nxt_row = r + row_axis[k];
            int nxt_col = c + col_axis[k];
            
            if(nxt_row < 0 || nxt_row >= n || nxt_col < 0 || nxt_col >= m) continue;
            if(!visited[nxt_row][nxt_col] && graph[nxt_row][nxt_col]) {
                q.push({nxt_row, nxt_col});
                visited[nxt_row][nxt_col] = 1;
                size++;
            }
        }
    }
    return size;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(graph[i][j] && !visited[i][j]) {
                int size = bfs(i, j);
                max_size = max(max_size, size);
                cnt++;
            }
        }
    }

    cout << cnt << '\n' << max_size;
}