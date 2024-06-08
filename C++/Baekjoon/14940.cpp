#include <iostream>
#include <queue>
#define MAX 2001
using namespace std;

int map[MAX/2][MAX];
bool visited[MAX/2][MAX];
int dist[MAX/2][MAX];

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};
int n, m;

void bfs(int start_r, int start_c) {
    queue<pair<int, int>> q;
    visited[start_r][start_c] = 1;
    dist[start_r][start_c] = 0;
    q.push({start_r, start_c});

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int d_row = row + row_axis[i];
            int d_col = col + col_axis[i];

            if(d_row <= 0 || d_col <= 0 || d_row > m || d_col > n) continue;
            if(map[d_row][d_col] == 1 && !visited[d_row][d_col]) {
                q.push({d_row, d_col});
                visited[d_row][d_col] = 1;
                dist[d_row][d_col] = dist[row][col] + 1;
            }
        }
    }
}


int main() {
    cin >> m >> n;

    int target_r, target_c;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) target_r = i, target_c = j;
        }
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = -1;
        }
    }

    bfs(target_r, target_c);

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(map[i][j] == 0) dist[i][j] = 0;
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}