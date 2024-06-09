#include <bits/stdc++.h>
#define MAX 21
using namespace std;

char graph[MAX][MAX];
bool visited[26] = {0,};
int R, C;
int max_cnt = 0;

int row_axis[4] = {1, -1, 0, 0};
int col_axis[4] = {0, 0, -1, 1};

bool compare(int a, int b) {
    if(a > b) return true;
    else return false;
}

void dfs(int r, int c, int cnt) {
    max_cnt = max(cnt, max_cnt);

    for(int i = 0; i < 4; i++) {
        int nxt_row = r + row_axis[i];
        int nxt_col = c + col_axis[i];

        if(nxt_row < 0 || nxt_row >= R || nxt_col < 0 || nxt_col >= C) continue;
        if(visited[graph[nxt_row][nxt_col] - 'A']) continue;

        visited[graph[nxt_row][nxt_col] - 'A'] = 1;
        dfs(nxt_row, nxt_col, cnt + 1);
        visited[graph[nxt_row][nxt_col] - 'A'] = 0;

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    string tmp;
    for(int i = 0; i < R; i++) {
        cin >> tmp;
        
        for(int j = 0; j < C; j++) {
            graph[i][j] = tmp[j];
        }
    }

    visited[graph[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    visited[graph[0][0] - 'A'] = 0;

    cout << max_cnt;
}