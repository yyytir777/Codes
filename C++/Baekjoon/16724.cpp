// 16724 cpp
#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, m, ans = 0;
int graph[MAX][MAX];
int visited[MAX][MAX] = {0,};
int row_aixs[4] = {-1, 1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};

void dfs(int r, int c) {
    visited[r][c] = 1;
    int nxt_r = r + row_aixs[graph[r][c]];
    int nxt_c = c + col_axis[graph[r][c]];

    if(nxt_r < 0 || nxt_r >= n || nxt_c < 0 || nxt_c >= m) return;

    // 사이클이 완성되었을 때 count
    if(visited[nxt_r][nxt_c] == 1) ans++;
    else if(visited[nxt_r][nxt_c] == 0) dfs(nxt_r, nxt_c);
    visited[r][c] = 2;
    return;
}

void input() {
    cin >> n >> m;

    char input;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> input;
            if(input == 'U') graph[i][j] = 0;
            else if(input == 'D') graph[i][j] = 1;
            else if(input == 'L') graph[i][j] = 2;
            else if(input == 'R') graph[i][j] = 3;
        }
    }
}

void print_graph() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                dfs(i,j);
            }
        }
    }
    cout << ans;
}

int main() {
    input();
    solve();
    return 0;
}