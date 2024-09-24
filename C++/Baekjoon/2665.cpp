#include <bits/stdc++.h>
#define MAX 51
#define B 0
#define W 1
#define INF 987654321
using namespace std;

queue<pair<int, int>> q;
int cnt[MAX][MAX];
int graph[MAX][MAX];
int row_axis[4] = {0, 0, 1, -1};
int col_axis[4] = {1, -1, 0, 0};
int n;

void init_cnt() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cnt[i][j] = INF;
        }
    }
}
void bfs(pair<int, int> start) {
    q.push(start);
    cnt[start.first][start.second] = 0;

    while(!q.empty()) {
        pair<int, int> cur_node = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int next_row = cur_node.first + row_axis[i];
            int next_col = cur_node.second + col_axis[i];

            if (next_row <= 0 || next_row > n || next_col <= 0 || next_col > n) continue;

            if (graph[next_row][next_col] == 1) {
                if(cnt[next_row][next_col] > cnt[cur_node.first][cur_node.second]) {
                    cnt[next_row][next_col] = cnt[cur_node.first][cur_node.second];
                    q.push({next_row, next_col});
                }
            }
            else {
                if(cnt[next_row][next_col] > cnt[cur_node.first][cur_node.second] + 1) {
                    cnt[next_row][next_col] = cnt[cur_node.first][cur_node.second] + 1;
                    q.push({next_row, next_col});
                }
            }
        }
    }
}

int main() {
    cin >> n;

    string tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= n; j++) {
            graph[i][j] = tmp[j-1] - 48;
        }
    }

    init_cnt();
    bfs({1,1});
    cout << cnt[n][n];

    return 0;
}