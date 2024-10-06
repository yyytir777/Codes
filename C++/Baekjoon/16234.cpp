#include <bits/stdc++.h>
#include <vector>
#define MAX 51
using namespace std;

bool flag = false;
int n, l, r;
int A[MAX][MAX] = {0,};
queue<pair<int, int>> q;
bool visited[MAX][MAX];
int sum = 0;

int row_axis[4] = {0, 0, -1, 1};
int col_axis[4] = {1, -1, 0, 0};

void init_visited() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[i][j]) {
                visited[i][j] = 0;
            }
        }
    }
}

vector<pair<int, int>> bfs(int a, int b) {
    vector<pair<int, int>> v;
    q.push({a,b});
    v.push_back({a,b});
    visited[a][b] = 1;
    sum += A[a][b];

    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();

        int row = node.first;
        int col = node.second;

        for(int i = 0; i < 4; i++) {
            int next_row = row + row_axis[i];
            int next_col = col + col_axis[i];
            pair<int, int> next_node = {next_row, next_col};
            if(next_row <= 0 || next_row > n || next_col <= 0 || next_col > n) continue;

            int diff = abs(A[next_row][next_col] - A[row][col]);
            if(l > diff || r < diff) continue;
            if(visited[next_row][next_col]) continue;

            q.push(next_node);
            v.push_back(next_node);
            visited[next_row][next_col] = 1;
            sum += A[next_row][next_col];
        }
    }
    return v;
}

int main() {
    cin >> n >> l >> r;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    int days = 0;
    while(true) {
        init_visited();
        flag = 0;

        // 인구 이동 시작
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                vector<pair<int, int>> migration_cnt;
                migration_cnt.clear();
                if(!visited[i][j]) {
                    sum = 0;
                    migration_cnt = bfs(i,j);
                }

                // 인구 이동이 발생했을 시
                if(migration_cnt.size() >= 2) {
                    flag = true;
                    int length = migration_cnt.size();
                    int avg = sum / length;

                    for(pair<int, int> node : migration_cnt) {
                        A[node.first][node.second] = avg;
                    }
                }
            }
        }
        if(!flag) break;
        else days++;
    }

    cout << days;
    return 0;
}