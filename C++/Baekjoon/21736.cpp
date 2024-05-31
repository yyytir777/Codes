#include <bits/stdc++.h>
#define MAX 601
using namespace std;

int n, m, cnt = 0;
char graph[MAX][MAX];
queue<pair<int, int>> q;
bool visited[MAX][MAX] = {0,};

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};

void bfs(int i, int j) {
    q.push({i, j});
    visited[i][j] = 1;

    while(!q.empty()) {
        pair<int, int> point = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int row = point.first + row_axis[i];
            int col = point.second + col_axis[i];

            if(row < 0 || row >= n || col < 0 || col >= m) continue;
            if(!visited[row][col] && graph[row][col] != 'X') {
                if(graph[row][col] == 'P') cnt++;
                q.push({row, col});
                visited[row][col] = 1;
            }
        }
    }
}

int main() {
    int x, y;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'I') {
                x = i;
                y = j;
            }
        }
    }

    bfs(x, y);

    if(cnt == 0) cout << "TT";
    else cout << cnt;
}